# Makefile with dependencies management (Q4)

CXX        = clang++
CXXFLAGS   = -Wall  -std=c++20
DEPFLAGS   = -MMD
LDFLAGS    =
SRCS       = main.cpp Encrypt.cpp EncryptHelper.cpp Enigma.cpp Enigma2.cpp EnigmaM3.cpp PairSwitch.cpp Rotor.cpp
OBJS       = $(SRCS:.cpp=.o)
TARGET     = app
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)
