
#################################################
# May be useful in the future
# 
# ${1}: Source file
# ${2}: Object file to generate
# ${3}: Extra flags
#
#
#define COMPILE
#${2}: ${1}
#	$(shell mkdir -p $(dir ${2}))
#
#ifeq ($(suffix ${1}),.cpp)
#	${CXX} -c ${1} -o ${2} ${INCLUDE} ${CXXFLAGS} ${3}
#else
#	${C} -c ${1} -o ${2} ${INCLUDE} ${CFLAGS} ${3}
#endif
#endef


# ${1}: Source file
define SRC2OBJ
$(subst .c,.o,$(subst .cpp,.o,$(subst src,${OBJ_PATH},${1})))
endef
