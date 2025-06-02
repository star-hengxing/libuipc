#pragma once
#include <string_view>
#include <uipc/common/vector.h>
#include <uipc/common/string.h>
#include <uipc/geometry/geometry.h>
#include <uipc/common/unordered_map.h>
#include <uipc/common/type_traits.h>
#include <uipc/geometry/geometry_collection.h>

namespace uipc::core::internal
{
class Scene;
}

namespace uipc::core
{
class ObjectSnapshot;
class Scene;

class UIPC_CORE_API IObject
{
  public:
    virtual ~IObject() = default;
    [[nodiscard]] std::string_view name() const noexcept;
    [[nodiscard]] IndexT           id() const noexcept;

  protected:
    virtual std::string_view get_name() const noexcept = 0;
    virtual IndexT           get_id() const noexcept   = 0;
};

class Object;

template <std::derived_from<geometry::Geometry> GeometryT>
class ObjectGeometrySlots
{
    using NonConstGeometryT = std::remove_const_t<GeometryT>;
    using AutoGeometrySlot =
        typename propagate_const<GeometryT, geometry::GeometrySlotT<NonConstGeometryT>>::type;

  public:
    S<AutoGeometrySlot> geometry;
    S<AutoGeometrySlot> rest_geometry;
};

template <>
class UIPC_CORE_API ObjectGeometrySlots<geometry::Geometry>
{
  public:
    S<geometry::GeometrySlot> geometry;
    S<geometry::GeometrySlot> rest_geometry;
};

template <>
class UIPC_CORE_API ObjectGeometrySlots<const geometry::Geometry>
{
  public:
    S<const geometry::GeometrySlot> geometry;
    S<const geometry::GeometrySlot> rest_geometry;
};

class UIPC_CORE_API Object : public IObject
{
    friend class Scene;
    friend class Animation;
    friend class ObjectCollection;
    friend class SceneFactory;
    friend class ObjectSnapshot;

  public:
    class UIPC_CORE_API Geometries
    {
        friend class Object;

      public:
        template <std::derived_from<geometry::Geometry> GeometryT>
            requires(!std::is_abstract_v<GeometryT>)
        ObjectGeometrySlots<GeometryT> create(const GeometryT& geometry) &&;

        template <std::derived_from<geometry::Geometry> GeometryT>
            requires(!std::is_abstract_v<GeometryT>)
        ObjectGeometrySlots<GeometryT> create(const GeometryT& geometry,
                                              const GeometryT& rest_geometry) &&;


        span<const IndexT> ids() && noexcept;

      private:
        Geometries(Object& object) noexcept;
        Object& m_object;
    };

    class UIPC_CORE_API CGeometries
    {
        friend class Object;

      public:
        span<const IndexT> ids() && noexcept;

      private:
        CGeometries(const Object& object) noexcept;
        const Object& m_object;
    };

    Object(internal::Scene& scene, IndexT id, std::string_view name = "") noexcept;
    Object() noexcept;
    Object(Object&&) = default;
    ~Object();

    Object(const Object&)            = delete;
    Object& operator=(const Object&) = delete;
    Object& operator=(Object&&)      = delete;

    [[nodiscard]] Geometries  geometries() noexcept;
    [[nodiscard]] CGeometries geometries() const noexcept;

  protected:
    [[nodiscard]] std::string_view get_name() const noexcept override;
    [[nodiscard]] IndexT           get_id() const noexcept override;

  private:
    friend struct fmt::formatter<Object>;

    internal::Scene*              m_scene = nullptr;
    IndexT                        m_id;
    string                        m_name;
    vector<IndexT>                m_geometry_ids;
    geometry::GeometryCollection& geometry_collection() noexcept;
    geometry::GeometryCollection& rest_geometry_collection() noexcept;
    bool                          scene_started() const noexcept;
    bool                          scene_pending() const noexcept;

    void build_from(span<const IndexT> geo_ids) noexcept;
    void update_from(const ObjectSnapshot& snapshot) noexcept;

    friend void to_json(Json& j, const Object& object) noexcept;
    friend void from_json(const Json& j, Object& object) noexcept;
};

void to_json(Json& j, const Object& object) noexcept;
void from_json(const Json& j, Object& object) noexcept;
}  // namespace uipc::core

namespace fmt
{
template <>
struct UIPC_CORE_API formatter<uipc::core::Object> : formatter<string_view>
{
    appender format(const uipc::core::Object& c, format_context& ctx) const;
};
}  // namespace fmt

#include "details/object.inl"