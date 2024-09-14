# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 15:48:30 by andrefranci       #+#    #+#              #
#    Updated: 2024/09/14 15:41:39 by andrefranci      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++11 -g -fsanitize=address #-fstandalone-debug -fsanitize=address

# Directories
SRCDIR = src
OBJDIR = objs

# Source Files

SRCS =  $(SRCDIR)/main.cpp \
		$(SRCDIR)/School.cpp \
		$(SRCDIR)/Room.cpp \
		$(SRCDIR)/Person.cpp \
		$(SRCDIR)/Staff.cpp \
		$(SRCDIR)/Classroom.cpp \
		$(SRCDIR)/Form.cpp \
		$(SRCDIR)/Course.cpp \
		$(SRCDIR)/CourseFinishedForm.cpp \
		$(SRCDIR)/Courtyard.cpp \
		$(SRCDIR)/Headmaster.cpp \
		$(SRCDIR)/HeadmasterOffice.cpp \
		$(SRCDIR)/NeedCourseCreationForm.cpp \
		$(SRCDIR)/NeedMoreClassRoomForm.cpp \
		$(SRCDIR)/Professor.cpp \
		$(SRCDIR)/SecretarialOffice.cpp \
		$(SRCDIR)/Secretary.cpp \
		$(SRCDIR)/StaffRestRoom.cpp \
		$(SRCDIR)/Student.cpp \
		$(SRCDIR)/SubscriptionToCourseForm.cpp


OBJS = 	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Targets
NAME = Facade

all: 	$(NAME)


clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -f $(NAME)

run:	fclean all
		./$(NAME)

re:		fclean all


valgrind: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
		

$(NAME): 	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o  $(NAME) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re run test