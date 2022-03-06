EXECUTABLE = main



#FILES 
BUILDDIR = build
SOURCEDIR = src
INCLUDEDIR = includes
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))



#COMPILER OPTIONS 
CXX = c++
LDFLAGS = -lpthread -lmysqlcppconn
FLAGS = -std=c++2a -Wall -g $(addprefix -I,$(INCLUDEDIR)) 


all: dir $(BUILDDIR)/$(EXECUTABLE) 

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ ${LDFLAGS}

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CXX) $(FLAGS) ${LDFLAGS} -c $< -o $@

clean:
	-@$(RM) -f $(BUILDDIR)/*.o

clean-all: clean
	-@$(RM) -f $(BUILDDIR)/$(EXECUTABLE)
	-@$(RM) -rf $(BUILDDIR) 
