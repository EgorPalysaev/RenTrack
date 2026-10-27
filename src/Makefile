CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lsqlite3 

SOURCES = main.c menu.c auth.c registration.c \
          services/data_registration.c \
          services/utils.c \
          services/add_premise.c \
          repositories/registration_repo.c \
          repositories/user_data.c \
          repositories/show_all_data.c \
          repositories/auth_repo.c \
          repositories/add_premise_repo.c \
          database/database.c \
	  repositories/delete.c \
	  repositories/update_repo.c \
	  services/update_service.c \
	  repositories/rent_repo.c

app.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDLIBS)

clean:
	rm -f app.exe

