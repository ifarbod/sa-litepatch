set_languages("cxx23")

add_rules("mode.debug", "mode.release")

target("gtasa-litepatch")
    set_kind("shared")
    set_extension(".asi")
    add_files("src/*.cpp")

    after_link(function (target)
        os.cp(target:targetfile(), "C:/Games/iFarbod/Calineva Dev/scripts")
        os.cp(target:symbolfile(), "C:/Games/iFarbod/Calineva Dev/scripts")
    end)

    add_syslinks("user32")
