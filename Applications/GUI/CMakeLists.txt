# GUI Application CMakeLists.txt
#


# Ensure that NDEBUG macro is manually defined when not in Debug configuration
add_compile_definitions($<$<NOT:$<CONFIG:Debug>>:NDEBUG>)

# Ensures qDebug() does not write to stderr in non-debug configuration(s)
add_compile_definitions($<$<NOT:$<CONFIG:Debug>>:QT_NO_DEBUG_OUTPUT>)