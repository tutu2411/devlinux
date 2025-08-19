CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = system_info

SRCS = main.c \
	   model/cpu_infors/cpu_infors.c \
	   model/data_model/system_infor_model.c \
	   view/system_infor_view.c \
	   controller/system_infor_controller.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)


