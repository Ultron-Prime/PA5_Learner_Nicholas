TARGET = proj5
CXX = g++
CXX_FLAGS = -Wall

all: $(TARGET)

$(TARGET): $(TARGET).o Vehicle.o Car.o strprgms.o
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp Vehicle.o Car.o strprgms.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp Vehicle.h Car.h strprgms.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

Vehicle.o: Vehicle.cpp Vehicle.h
	$(CXX) $(CXX_FLAGS) -c Vehicle.cpp

Car.o: Car.cpp Car.h
	$(CXX) $(CXX_FLAGS) -c Car.cpp

strprgms.o: strprgms.cpp strprgms.h
	$(CXX) $(CXX_FLAGS) -c strprgms.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
