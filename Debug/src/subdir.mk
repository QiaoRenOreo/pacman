################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/UI.cpp \
../src/character.cpp \
../src/game.cpp \
../src/ghost.cpp \
../src/main.cpp \
../src/pacman.cpp 

OBJS += \
./src/UI.o \
./src/character.o \
./src/game.o \
./src/ghost.o \
./src/main.o \
./src/pacman.o 

CPP_DEPS += \
./src/UI.d \
./src/character.d \
./src/game.d \
./src/ghost.d \
./src/main.d \
./src/pacman.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/alex/workspace/PACMANfresh/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


