add_requires(
    "eigen", "nlohmann_json", "cppitertools", "magic_enum", "tinygltf", "dylib", "cpptrace",
    -- Use non-header-only spdlog and fmt
    "spdlog[header_only=n,fmt_external=y] <=1.15.2"
)

-- https://stackoverflow.com/questions/78935510/no-member-named-join-in-namespace-fmt
-- https://forums.developer.nvidia.com/t/utf-8-option-for-the-host-function-in-cuda-msvc/312739
add_requireconfs("spdlog.fmt", {override = true, version = "<11"})

-- find_package(zstd CONFIG REQUIRED) failed
add_requireconfs("**.ztsd", {system = false})

target("core")
    add_rules("component")
    add_files("**.cpp")
    add_headerfiles(
        path.join(os.projectdir(), "include/uipc/core/**.h"),
        path.join(os.projectdir(), "include/uipc/core/**.inl")
    )

    add_defines("UIPC_RUNTIME_CHECK")

    if is_plat("linux") then
        add_syslinks("dl")
    end

    add_packages(
        "eigen", "nlohmann_json", "cppitertools", "magic_enum", "tinygltf", "dylib",
        "cpptrace", "spdlog",
        {public = true}
    )
