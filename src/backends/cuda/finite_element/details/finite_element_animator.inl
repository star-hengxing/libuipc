namespace uipc::backend::cuda
{
template <typename ForEach, typename ViewGetter>
void FiniteElementAnimator::FilteredInfo::for_each(span<S<geometry::GeometrySlot>> geo_slots,
                                                   ViewGetter&& view_getter,
                                                   ForEach&& for_each_action) noexcept
{
    auto geo_infos = anim_geo_infos();
    FiniteElementMethod::_for_each(geo_infos,
                                   geo_slots,
                                   std::forward<ViewGetter>(view_getter),
                                   std::forward<ForEach>(for_each_action));
}
}  // namespace uipc::backend::cuda
