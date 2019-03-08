set_property(TARGET lnetd PROPERTY CXX_STANDARD 17)
set_property(TARGET lnetd PROPERTY CXX_STANDARD_REQUIRED ON)

# For <filesystem>
target_link_libraries(${TARGETNAME} lnetd "stdc++fs")
