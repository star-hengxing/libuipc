#pragma once
#include <uipc/core/contact_element.h>
#include <uipc/core/contact_model.h>
#include <uipc/common/json.h>
#include <uipc/common/span.h>
#include <uipc/core/contact_model_collection.h>

namespace uipc::core::internal
{
class Scene;
}

namespace uipc::backend
{
class ContactTabularVisitor;
}

namespace uipc::core
{
class UIPC_CORE_API ContactTabular final
{
    friend class uipc::backend::ContactTabularVisitor;
    friend class SceneSnapshot;
    friend class Scene;
    friend class internal::Scene;

  public:
    ContactTabular() noexcept;
    ~ContactTabular() noexcept;
    // delete copy_from
    ContactTabular(const ContactTabular&)            = delete;
    ContactTabular& operator=(const ContactTabular&) = delete;

    ContactElement create(std::string_view name = "") noexcept;

    IndexT insert(const ContactElement& L,
                  const ContactElement& R,
                  Float                 friction_rate,
                  Float                 resistance,
                  bool                  enable = true,
                  const Json&           config = default_config());

    ContactModel at(SizeT i, SizeT j) const;

    void default_model(Float       friction_rate,
                       Float       resistance,
                       bool        enable = true,
                       const Json& config = default_config()) noexcept;

    ContactElement default_element() noexcept;
    ContactModel   default_model() const noexcept;


    friend void to_json(Json& j, const ContactTabular& ct);

    SizeT element_count() const noexcept;

    static Json default_config() noexcept;

    ContactModelCollection  contact_models() noexcept;
    CContactModelCollection contact_models() const noexcept;

  private:
    class Impl;
    U<Impl> m_impl;
    friend class SceneFactory;
    geometry::AttributeCollection& internal_contact_models() const noexcept;
    span<ContactElement>           contact_elements() const noexcept;
    void build_from(const geometry::AttributeCollection& ac, span<const ContactElement> ce);
    void update_from(const geometry::AttributeCollectionCommit& acc,
                     span<const ContactElement>                 ce);
};

void to_json(Json& j, const ContactTabular& ct);
}  // namespace uipc::core
