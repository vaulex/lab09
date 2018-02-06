# Лабораторная работа №9. Отчет.

## Задание на лабораторную работу:

- [ ] 1. Создать публичный репозиторий с названием **lab09** на сервисе **GitHub**
- [ ] 2. Ознакомиться со ссылками учебного материала
- [ ] 3. Получить токен для доступа к репозиториям сервиса **GitHub**
- [ ] 4. Сгенерировать GPG ключ и добавить его к аккаунту сервиса **GitHub**
- [ ] 5. Выполнить инструкцию учебного материала
- [ ] 6. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Выполнение работы.
	
В соответствии с последовательностью, определенной заданием на лабораторную работу, были выполнены следующие действия:
- [X] 1. Для успешного выполнения задания создан новый пустой репозиторий lab09 с лицензией MIT.
- [X] 2. Проведено ознакомление по приведенным ссылкам со следующими материалами по [Create Release](https://help.github.com/articles/creating-releases/), [Get GitHub Token](https://help.github.com/articles/creating-a-personal-access-token-for-the-command-line/), [Signing Commits](https://help.github.com/articles/signing-commits-with-gpg/), [Go Setup](http://www.golangbootcamp.com/book/get_setup), [github-release](https://github.com/aktau/github-release).
- [X] 3. Создан токен для доступа к сервисам **Github**:

```ShellSession
be10e9a871be578b35804db67cc64784195ed2b6
```

- [X] 4. Создан и добавлен в профиль CPG-ключ:

```ShellSession
gpg: ключ 4FEF0427 помечен как абсолютно доверенный.
открытый и закрытый ключи созданы и подписаны.

gpg: проверка таблицы доверия
gpg: требуется 3 с ограниченным доверием, 1 с полным, модель доверия PGP
gpg: глубина: 0  верных:   1  подписанных:   0  доверие: 0-, 0q, 0n, 0m, 0f, 1u
gpg: срок следующей проверки таблицы доверия 2018-08-05
pub   4096R/4FEF0427 2018-02-06 [годен до: 2018-08-05]
      Отпечаток ключа = DF58 F0E2 11DC 62C0 A15A  BE4E DC96 8CB9 4FEF 0427
uid                  Vaulex (admin) <krasauchek.s.iy@ya.ru>
sub   4096R/95D0945A 2018-02-06 [годен до: 2018-08-05]
```

- [X] 5. Выполнена следующая последовательность команд:

## Tutorial

```ShellSession
$ export GITHUB_TOKEN=be10e9a871be578b35804db67cc64784195ed2b6
$ export GITHUB_USERNAME=vaulex
$ alias gsed=sed # for *-nix system
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
$ go get github.com/aktau/github-release
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab08 projects/lab09
$ cd projects/lab09
$ git remote remove origin
$ git remote add origin git@github.com:${GITHUB_USERNAME}/lab09
```

```ShellSession
$ gsed -i 's/lab08/lab09/g' README.md
```

```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"
$ cmake --build _build --target package
```

```ShellSession
$ travis login --auto
$ travis enable
```

```ShellSession
$ git tag -s v0.1.0.0
$ git tag -v v0.1.0.0
$ git push origin master --tags
```

```ShellSession
$ github-release --version
$ github-release info -u ${GITHUB_USERNAME} -r lab09
$ github-release release \
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "libprint" \
    --description "my first release"
```

```ShellSession
$ export PACKAGE_OS=`uname -s` PACKAGE_ARCH=`uname -m` 
$ export PACKAGE_FILENAME=print-${PACKAGE_OS}-${PACKAGE_ARCH}.tar.gz
$ github-release upload \
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "${PACKAGE_FILENAME}" \
    --file _build/*.tar.gz
```

```ShellSession
$ github-release info -u ${GITHUB_USERNAME} -r lab09
$ wget https://github.com/${GITHUB_USERNAME}/lab09/releases/download/v0.1.0.0/${PACKAGE_FILENAME}
$ tar -ztf ${PACKAGE_FILENAME}
```

## Report

```ShellSession
$ popd
$ export LAB_NUMBER=09
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

- [X] 6. Составлен отчет о работе в формате MD, ссылка отправлена в **slack**.

	
>## Выводы:
>В ходе проделанной работы проведена ознакомительная работа со средством механизмом **Release** на **Github**, созданы метки, опубликова релиз **v0.1.0.0**, для верификации меток и коммитов использован **CPG-ключ**, дополнительно получен снимок экрана и файл релиза **print-Linux-i686.tar.gz**.
