# source files in this project 
PROJECT_NAME=assg08

assg_src  = AList.cpp \
	    AListIterator.cpp \
	    List.cpp \
	    ListException.cpp \
	    ListIterator.cpp \
	    LList.cpp \
	    LListIterator.cpp \

test_src  = ${PROJECT_NAME}-AList-tests.cpp \
	    ${PROJECT_NAME}-LList-tests.cpp \
	    ${assg_src}

sim_src   = ${PROJECT_NAME}-sim.cpp \
	    ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include include/Makefile.inc

# assignment header file specific dependencies
${OBJ_DIR}/AList.o: ${INC_DIR}/AList.hpp
${OBJ_DIR}/AListIterator.o: ${INC_DIR}/AListIterator.hpp
${OBJ_DIR}/List.o: ${INC_DIR}/List.hpp
${OBJ_DIR}/ListException.o: ${INC_DIR}/ListException.hpp
${OBJ_DIR}/ListIterator.o: ${INC_DIR}/ListIterator.hpp
${OBJ_DIR}/LList.o: ${INC_DIR}/LList.hpp
${OBJ_DIR}/LListIterator.o: ${INC_DIR}/LListIterator.hpp
${OBJ_DIR}/${PROJECT_NAME}-AList-tests.o: ${INC_DIR}/AList.hpp ${INC_DIR}/ListException.hpp ${INC_DIR}/ListIterator.hpp
${OBJ_DIR}/${PROJECT_NAME}-LList-tests.o: ${INC_DIR}/LList.hpp ${INC_DIR}/ListException.hpp ${INC_DIR}/ListIterator.hpp
${OBJ_DIR}/${PROJECT_NAME}-sim.o: ${INC_DIR}/List.hpp
