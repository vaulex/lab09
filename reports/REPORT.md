[![Build Status](https://travis-ci.org/vaulex/lab05.svg?branch=master)](https://travis-ci.org/vaulex/lab05)
## Лабораторная работа №5. Отчет.

## Задание на лабораторную работу:

- [X] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [X] 2. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [X] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [X] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [X] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [X] 8. Выполнить инструкцию учебного материала
- [X] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Выполнение работы.
	
В соответствии с последовательностью, определенной заданием на лабораторную работу, были выполнены следующие действия:
- [X] 1. Выполнена авторизация на сервисе **Travis CI** с использованием Github-аккаунта.
- [X] 2. Для успешного выполнения задания создан новый пустой репозиторий lab05 с лицензией MIT.
- [X] 3. Проведено ознакомление по приведенным ссылкам со следующими материалами по Travis Client, AppVeyour, GitLab CI.
- [X] 4. Включена инеграция репозитория **lab05** с сервисом **Travis CI**.
- [X] 5. Создан токен
```ShellSession
cffee121dcde080d6e766406b67a984c9aa4bc71
```
для **Travis CLI** с правами repo и user.
- [X] 6. Получен код значка сервиса **Travis CI** в формате Markdown:
```ShellSession
[![Build Status](https://travis-ci.org/vaulex/lab05.svg?branch=master)](https://travis-ci.org/vaulex/lab05)
```
- [X] 7. Установлен Travis CLI.
- [X] 8. Выполнена следующая последовательность команд:

## Tutorial
```ShellSession
$ export GITHUB_USERNAME=vaulex
$ export GITHUB_TOKEN=ke2f610e566b6bff59c6534ca260455c8e91baaa6
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate

$ \curl -sSL https://get.rvm.io | bash -s -- --ignore-dotfiles
$ echo "source $HOME/.rvm/scripts/rvm" >> scripts/activate
$ rvm autolibs disable
$ rvm install ruby-2.4.2
$ rvm use 2.4.2 --default
$ gem install travis

$ git clone https://github.com/${GITHUB_USERNAME}/lab04 projects/lab05
$ cd projects/lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05

$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF

$ travis login --github-token ${GITHUB_TOKEN}
$ travis lint

$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md

$ git add .travis.yml
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
$ travis lint
$ travis accounts
$ travis sync
$ travis repos
$ travis enable
$ travis whatsup
$ travis branches
$ travis history
$ travis show
```
## Report
```ShellSession
$ popd
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```
- [X] 9. Составлен отчет о работе в формате MD, ссылка отправлена в **slack**.

	
## Выводы:
В ходе проделанной работы проведена ознакомительная работа с работой сервиса **Travis CI**, осуществлена его интеграция с репозиторием на **Github**, выполнена автоматизаированная сборка проекта, получен значек сервиса **Travis CI**.
