This is a console app for management premises, rent(start and rent), and users data
## Possebilites
- Users registration;
- Users authentication;
- Data management;
- Local database.
## Структура проекта
```
RenTrack/
│
├── docs/
│
├── src/
│   │
│   ├── rentrack.h
│   ├── main.c              # App start-up
│   ├── menu.c              # Console menu
│   │
│   ├── database/           # Database, SQL-schema
│   ├── repositories/       # Database interaction
│   └── services/           # Service layout
│
├── tests/
│   │
│   └── test_main.c
│        
├── README.md
└── requirements.txt
```
## Architecture
```
Console Interface (main.с, menu.с)
     │
     ▼
Services
     │
     ▼
Repositories
     │
     ▼
Database
```
## Main component
**`main.c`** - Complete initialization of nessecerary component and run the app 

**`menu.c`** - Console user interface   

**`repositories`** - CRUD  

**`services`** - Associating user and repository 

**`database`**  Initializate database 

## Installation
Be aware that you need to pre-install docker
```
git clone https://github.com/EgorPalysaev/RenTrack.git
cd RenTrack/
```
Based on your OS complete:

```make arch```

```make fedora```

```make ubuntu```

```make mac```

```make win```

Or you can download container from docker-hub

```docker pull egorpalysaev/rent-tracking-database```

If you have pre-installed GCC/Clang compiler and SQLite, you can simply run:

```make```
