################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MainJokes1.cpp \
../Student.cpp \
../TreeInterface.cpp \
../bst.cpp \
../bstNode.cpp 

CPP_DEPS += \
./MainJokes1.d \
./Student.d \
./TreeInterface.d \
./bst.d \
./bstNode.d 

OBJS += \
./MainJokes1.o \
./Student.o \
./TreeInterface.o \
./bst.o \
./bstNode.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./MainJokes1.d ./MainJokes1.o ./Student.d ./Student.o ./TreeInterface.d ./TreeInterface.o ./bst.d ./bst.o ./bstNode.d ./bstNode.o

.PHONY: clean--2e-

