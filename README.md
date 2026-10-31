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
├── docs/                       # Документация проекта
│   └── UseCase.plantuml        # Диаграмма вариантов использования
│
├── src/                        # Исходный код приложения
│   │
│   ├── rentrack.h
│   ├── main.c              # Точка входа в приложение
│   ├── auth.c              # Логика авторизации
│   ├── menu.c              # Консольное меню
│   │
│   ├── database/           # Работа с базой данных
│   ├── repositories/       # Доступ к данным
│   └── services/           # Бизнес-логика приложения
│
├── tests/                      # Автоматизированные тесты
│   │
│   ├── rentrack.h
│   └── test_main.c
│        
├── .gitignore                  # Исключения для Git
├── .git/
├── README.md                   # Документация проекта
└── requirements.txt            # Зависимости проекта
```
## Architecture
```
Пользователь
     │
     ▼
Консольный интерфейс
(main.с, menu.с, auth.с)
     │
     ▼
Сервисный слой
(services)
     │
     ▼
Слой доступа к данным
(repositories)
     │
     ▼
База данных
(database)
```
## Основные компоненты
**`main.c`**  
Точка входа в приложение. Выполняет инициализацию необходимых компонентов и запускает программу.  

**`menu.c`**  
Содержит логику взаимодействия с пользователем через консольное меню.    

**`repositories`**  
Содержит компоненты, отвечающие за получение, добавление, изменение и удаление данных.  

**`services`**  
Содержит бизнес-логику приложения и обеспечивает взаимодействие между пользовательским интерфейсом и слоем доступа к данным.  

**`database`**  
Содержит компоненты, необходимые для работы с базой данных и её инициализации.  

## Installation
Be aware that you need pre-install docker
```
git clone https://github.com/EgorPalysaev/RenTrack.git
cd RenTrack/
```
Based on your OS complete:
make arch
make fedora
make ubuntu
make mac
make win

Or you can download container from docker-hub

docker pull egorpalysaev/rent-tracking-database
