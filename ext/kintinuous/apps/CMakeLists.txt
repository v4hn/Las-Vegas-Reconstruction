include_directories(${CMAKE_SOURCE_DIR}/kfusion/include)
link_directories(${LSSR_LIBRARIES} /usr/lib/x86_64-linux-gnu/)

file(GLOB srcs *.cpp *.hpp)
add_executable(demo ${srcs})

target_link_libraries(demo 
	kfusion
	lvr_static
	lvrrply_static
	lvrlas_static
	lvrslam6d_static
	${OpenCV_LIBS}
	${Boost_SYSTEM_LIBRARY} 
	${Boost_PROGRAM_OPTIONS_LIBRARY}
	${Boost_FILESYSTEM_LIBRARY}
	${OPENGL_LIBRARY} 
	${GLUT_LIBRARIES}
	)


set_target_properties(demo PROPERTIES
    DEBUG_POSTFIX "d"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

install(TARGETS demo RUNTIME DESTINATION bin COMPONENT main)
install(FILES ${srcs} DESTINATION app COMPONENT main)
