#include <finite_element/finite_element_vertex_reporter.h>
#include <global_geometry/global_vertex_manager.h>
#include <kernel_cout.h>
#include <muda/ext/eigen/log_proxy.h>
#include <finite_element/finite_element_body_reporter.h>

namespace uipc::backend::cuda
{
REGISTER_SIM_SYSTEM(FiniteElementVertexReporter);

void FiniteElementVertexReporter::do_build(BuildInfo& info)
{
    m_impl.finite_element_method = &require<FiniteElementMethod>();
    m_impl.body_reporter         = &require<FiniteElementBodyReporter>();
}

void FiniteElementVertexReporter::Impl::report_count(VertexCountInfo& info)
{
    info.count(fem().xs.size());
}

void FiniteElementVertexReporter::Impl::report_attributes(VertexAttributeInfo& info)
{
    using namespace muda;

    info.contact_element_ids().copy_from(fem().h_vertex_contact_element_ids.data());

    info.dimensions().copy_from(fem().h_dimensions.data());
    info.thicknesses().copy_from(fem().thicknesses);

    info.body_ids().copy_from(fem().h_vertex_body_id.data());

    // fill the coindices for later use
    auto N = info.coindices().size();
    ParallelFor()
        .file_line(__FILE__, __LINE__)
        .apply(N,
               [coindices    = info.coindices().viewer().name("coindices"),
                src_pos      = fem().xs.cviewer().name("src_pos"),
                dst_pos      = info.positions().viewer().name("dst_pos"),
                src_rest_pos = fem().x_bars.cviewer().name("rest_pos"),
                body_offset  = body_reporter->body_offset(),
                dst_body_ids = info.body_ids().viewer().name("dst_body_ids"),
                dst_rest_pos = info.rest_positions().viewer().name("rest_pos")] __device__(int i) mutable
               {
                   coindices(i)    = i;
                   dst_pos(i)      = src_pos(i);
                   dst_rest_pos(i) = src_rest_pos(i);
                   dst_body_ids(i) += body_offset;  // offset by the global body offset
               });
}

void FiniteElementVertexReporter::Impl::report_displacements(VertexDisplacementInfo& info)
{
    using namespace muda;

    info.displacements().copy_from(fem().dxs);
}

void FiniteElementVertexReporter::do_report_count(VertexCountInfo& info)
{
    m_impl.report_count(info);
}
void FiniteElementVertexReporter::do_report_attributes(VertexAttributeInfo& info)
{
    m_impl.report_attributes(info);
}

void FiniteElementVertexReporter::do_report_displacements(VertexDisplacementInfo& info)
{
    m_impl.report_displacements(info);
}
}  // namespace uipc::backend::cuda
