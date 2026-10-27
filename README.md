# RenTrack
RenTrack — консольное приложение для управления помещениями. Проект предназначен для автоматизации основных процессов работы с арендной компанией  и их арендаторами. Приложение позволяет регистрировать пользователей, выполнять авторизацию и работать с данными арендной компании, включая помещения под аренду, арендаторов и аренды.
## Возможности
В проекте реализованы следующие основные возможности:
- Регистрация арендатора;
- Авторизация пользователей;
- Управление пользователями;
- Работа с помещениями;
- Работа с арендаторами;
- Хранение связи между помещениями и их характеристиками;
- Аренда помещений;
- Управление статусами аренды;
- Хранение данных в базе данных.
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
## Архитектура
Приложение построено с использованием многослойной архитектуры:
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
Такой разделение позволяет отделить пользовательский интерфейс от бизнес-логики и операий с данными.
## Основные компоненты
**`main.c`**  
Точка входа в приложение. Выполняет инициализацию необходимых компонентов и запускает программу.  

**`menu.c`**  
Содержит логику взаимодействия с пользователем через консольное меню.  

**`auth.c`**  
Отвечает за регистрацию и авторизацию пользователей.  

**`repositories`**  
Содержит компоненты, отвечающие за получение, добавление, изменение и удаление данных.  

**`services`**  
Содержит бизнес-логику приложения и обеспечивает взаимодействие между пользовательским интерфейсом и слоем доступа к данным.  

**`database`**  
Содержит компоненты, необходимые для работы с базой данных и её инициализации.  

## Требования
- Язык C 202311L или выше;
- Компилятор GCC 16.2.1 или выше;
- Git.
## Установка
### Клонирование репозитория
```
git clone https://github.com/EgorPalysaev/RenTrack.git
cd RenTrack/
```
## Запуск приложения
Из корневой папки выполните:  
```make```

```app.exe```  
## Используемые технологии
- C 2023;
- Git 2.55.0;
- VIM 9.2;
- GCC 16.2.1.
## Разработка
Исходный код проекта располагается в каталоге:

`src/rentrack/`

При разработке рекомендуется соблюдать следующую организацию кода:

- Модели предметной области размещать в models;
- Работу с базой данных размещать в repositories;
- Бизнес-логику размещать в services;
- Код пользовательского интерфейса размещать отдельно от бизнес-логики.


![US](https://sun9-71.vkuserphoto.ru/s/v1/ig2/o_bijlGoYE2lbgOr2b-e53vBtyb7rJcP62eQrdGbS-nsRQuZbVlPf5dtS-TR2X2keEHtHupWqNy1PvE6NyhOdGVkGvpiiQ.jpg?quality=95&as=32x13,48x19,72x28,108x42,160x63,240x94,360x142,480x189,540x212,640x252,720x283,1080x425,1280x503,1440x566,1533x603&from=bu&u=poJVA3qi46wDtpSxS2VK1lU3LKqmqwY24He1pmgON1Y&cs=1533x0)	
[![PS](https://mermaid.ink/img/pako:eNqdVutOGkEUfpXJJE0ggmVBxGJtM4Livd6tCj827hbXyi5ZILUlJtWm2lZb08ZfTdpn8EaK177CzBv1zAwsO8IPUxIuc-Y73znznTNnqeI1xzBxEr_adN6sretuGc2nszaCFwms0l_0hO3TE3pN73JBFA4_Q4OrWVxyddsIBCp2ycrbphEsWwUzMLUwMREMZnFOeg8KdArQ9Dc9ZV_YET2jdbbLDpHdj9gHtsN2gfiW3nn2UqWABlDEo0gJijSn-MEOAFYTTnVE_7L3tE7PIa0T9onWgKVOawh2ALDP2cAuInlcacE11OS6AKfrRlj6F_K4YUdycUGv2RGiN8Cww3aA94yeQLr0CkB_OK3wrNFLVDRdyzG8CEMiwjBEsLxTyJ1hsZOp8p2nyH6exdtyIwMbiB5DAA4YeWhyXAUQ4A5yqjeyWLVyXiIjgm20k2zw8z2Qn4HvhULjOY8K5zFw3lBqMSbs41VuV84wrpxhAhy9jFY3csAheiWIHiEt0qKbEOjJ9hz9zh56UqCnGkltoC6keXtTMjF_Mr-AbVeYXzSqYSkuL2Q9muXJ3HOabs8KZOLV9wrDv9mhRzgt_GaU0nP7jLDPqoWXW7OKbHMAsRG0cY3ts-_Az69FrSXynIKeF4QDA8hGj1G0hZpXUAv8ooobxT-7fMr6emVBQBf9MvW3-uRSts0VtIro-Qu4tt_YZ9H9UgYuDNuDW9LqoEV56OZB5--puwSxymahCOE6ZjR3Hy_NS2LxUmkvK6eQ2CiMNHj7yF4Kr2XFqwUDb56Jh14W6BVe_mPQ_xRq3hxNcskvYB2s57C85VORHdJbdsA-IvZVCHTDZxGfPlw0kN2jXhHUhHTsR0JUyWbvSUAG2zqLyPFKUu1DhaSUNiDp_xsERE5MMtQ2CoicdGS4fRiQYTV25oEXnGQkfqTjFScjjYBKEJ8-o51lHW1o1NS1oYzPcaw9P3_ViJx6ZByehD9FzWtsLxfM2pOmW9AtAxU39bd516nYBg7hvGsZOFl2K2YIFyQAnqtVTgUtv24WzCxOwk_XNCpbYUN3X4fXnE3HzeKsvQ3-Rd1ecZxCkwJo8-s4-UrfLMGqUjT0spm29LyrFzyra9qG6aYggTJOalEtJlhwsoq3cLKnN94dT2g9mqbFon1aNB7Cb3Ey3tcd0aKRRCIW0-I90SeJ7RB-J8JGuvsS8Qi8NC2hxWO9T0LYNKyy407Kfwjij8L2P9guLng?type=png)](https://mermaid.live/edit#pako:eNqdVutOGkEUfpXJJE0ggmVRisXaZgQFFW3rvQo_Nu4W18IuWSGtJSZq09qLrWnjryb2GahCSuulrzDzRj0zA8uO8MOUhMuc-c53znznzFlqeMMxTJzAz4vOy41N3a2gxVTORvAigXV6SuvskNbpBb3OB1E4_BCNr-fwtqvbRiBQtbetgm0awYpVMgNzS9lsMJjDeek9LtBJQNMf9Cf7yI7pGW2xA3aE7FHE3rB9dgDEV_Tas29XS2gMRTyKpKBIcYpv7BPAmsKphehftkdb9BzSqrP3tAksLdpEsAOAQ84GdhHJ40oJrokOVwOcLtph6V_I45Idy0WDXrBjRC-BYZ_tA-8ZrUO69A-AfnFa4dmkv1HZdC3H8CJMiAiTEMHyTiF3JsVOusZ3HiD7UQ7vyo00bCB6AgE4IHPb5LgKIMA15NRqZ7Fu5b1EMoJtqp9s8HMPyM_At6HQeM5TwnkanLeUWkwL-0yN25UzzChnyIKjl9H6Vh44RK8E0R2kRbp0WYGe7c3R7-yhZwV6rp3UFhpAmrc3JxPzJ3MKbAfC_LhdDUtxeSzr0SlP-obTk96sQCZefa8w_JsdeYRPhN9TpfTc_lTY59XCy615RbYFgNgI2rjJDtlX4OfXotkVeUFBLwrCsTFko7so2kUtKqglflHFjeKfAz5lfb2yJKDLfplGu33yW7bNH2gV0fMNuLZf2AfR_VIGLgx7B7ek20HL8tCdgy7eUHcFYlXMUhnC9c1o4SZemlfEYlVpLyuvkNgojDR4-8hWhdczxasLA2-eiYd-JtBrvPwnoP9PqHlnNMklv4AtsJ7D8opPRXZEr9gn9haxz0KgSz6L-PThooHsHvWaoCakbz8Soko2f0MCMt7TWUSOV5LsHSokqbQBSf3fICByYpKJnlFA5KQjk73DgEyqsdO3vOAkLfGZvlecZNoBlSA-fab6yzrV1qija1sZn-N0b37-qhE59cgMPAm_i5o32bt8MGfPmm5JtwxULuo7Bdep2gYO4YJrGThRcatmCJckAJ6rNU4FLb9plswcTsBP1zSqr8KG7r4IbzhFx83hnL0L_mXdXnOcEk4814vbwAG8hU1vVS0besVMWXrB1X0Y0zZMNwkZVHBCi2pRQYMTNfwKJ4bvxQZjcW1Y07Sh6IgWjYXwDk7ERgYjWjQSjw8NabHh6P34bgi_FnEjgyPxWARemhbXYkP37oewaVgVx52VfxHEP4XdfweOLsI)
