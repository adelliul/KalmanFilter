# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Output executable name
TARGET = kalman

# Source files
SRCS = main.cpp KalmanFilter.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the program
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp → .o
%.o: %.cpp KalmanFilter.h
	$(CXX) $(CXXFLAGS) -c $<

# Run the program
run: $(TARGET)
	./$(TARGET)

# Delete compiled files
clean:
	rm -f $(TARGET) *.o