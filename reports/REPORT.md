# Лабораторная работа №7. Отчет.

## Задание на лабораторную работу:

- [ ] 1. Создать публичный репозиторий с названием **lab07** на сервисе **GitHub**
- [ ] 2. Выполнить инструкцию учебного материала
- [ ] 3. Ознакомиться со ссылками учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Выполнение работы.
	
В соответствии с последовательностью, определенной заданием на лабораторную работу, были выполнены следующие действия:
- [X] 1. Для успешного выполнения задания создан новый пустой репозиторий lab07 с лицензией MIT.
- [X] 2. Выполнена следующая последовательность команд:

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=vaulex
$ export GITHUB_TOKEN=ke2f610e566b6bff59c6534ca260455c8e91baaa6
$ alias edit=vim
$ alias gsed=sed # for *-nix system
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```

```ShellSession
$ wget https://redirector.gvt1.com/edgedl/go/go1.9.2.linux-amd64.tar.gz
$ tar -C . -xzf go1.9.3.linux-386.tar.gz
$ rm -rf go1.9.3.linux-386.tar.gz
$ echo "export GOROOT=`pwd`/go" >> scripts/activate
$ echo "export GOPATH=`pwd`/go_modules" >> scripts/activate
$ echo "export PATH=\${PATH}:\${GOROOT}/bin" >> scripts/activate
$ echo "export PATH=\${PATH}:\${GOPATH}/bin" >> scripts/activate
$ source scripts/activate
$ go get github.com/prasmussen/gdrive
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab06 projects/lab07
$ cd projects/lab07
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab07
```

```ShellSession
$ mkdir docs
$ doxygen -g docs/doxygen.conf
$ cat docs/doxygen.conf | less
```

```ShellSession
$ gsed -i 's/\(PROJECT_NAME.*=\).*$/\1 print/g' docs/doxygen.conf
$ gsed -i 's/\(EXAMPLE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ gsed -i 's/\(INCLUDE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ gsed -i 's/\(EXTRACT_ALL.*=\).*$/\1 YES/g' docs/doxygen.conf
$ gsed -i 's/\(INPUT *=\).*$/\1 README.md include/g' docs/doxygen.conf
$ gsed -i 's/\(USE_MDFILE_AS_MAINPAGE.*=\).*$/\1 README.md/g' docs/doxygen.conf
$ gsed -i 's/\(OUTPUT_DIRECTORY.*=\).*$/\1 docs/g' docs/doxygen.conf
```

```ShellSession
$ gsed -i 's/lab06/lab07/g' README.md
```

```ShellSession
# документируем функции print 
$ edit include/print.hpp
```

```ShellSession
$ git add .
$ git commit -m"added doxygen.conf"
$ git push origin master
```

```ShellSession
$ travis login --auto
$ travis enable
```

```ShellSession
$ doxygen docs/doxygen.conf
$ ls | grep "[^docs]" | xargs rm -rf
$ mv docs/html/* . && rm -rf docs
$ git checkout -b gh-pages
$ git add .
$ git commit -m"added documentation"
$ git push origin gh-pages
$ git checkout master
```

```ShellSession
$ mkdir artifacts && cd artifacts
$ sleep 20s && gnome-screenshot --file artifacts/screenshot.png
# for macOS: $ screencapture -T 20 artifacts/screenshot.png
# open https://${GITHUB_USERNAME}.github.io/lab07/print_8hpp.html
$ gdrive upload screenshot.png
$ SCREENSHOT_ID=`gdrive list | grep screenshot | awk '{ print $1; }'`
$ gdrive share ${SCREENSHOT_ID} --role reader --type user --email rusdevops@gmail.com
$ echo https://drive.google.com/open?id=${SCREENSHOT_ID}
```

## Report

```ShellSession
$ popd
$ export LAB_NUMBER=07
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

- [X] 3. Проведено ознакомление по приведенным ссылкам со следующими материалами по [HTML](https://ru.wikipedia.org/wiki/HTML), [LAΤΕΧ](https://ru.wikipedia.org/wiki/LaTeX), [man](https://ru.wikipedia.org/wiki/Man_(%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%B0_Unix)), [CHM](https://ru.wikipedia.org/wiki/HTMLHelp), [PostScript](https://ru.wikipedia.org/wiki/PostScript).
- [X] 4. Составлен отчет о работе в формате MD, ссылка отправлена в **slack**.

	
>## Выводы:
>В ходе проделанной работы проведена ознакомительная работа с системой документирования исходного кода **Doxygen**, создан конфигурационный файл системы и создана документация, документация в соответствии с требованиями **Github** загружена на ветку **gh-pages** репозитоиря, результат доступен по https://vaulex.github.io/lab07/index.html, получен снимок экрана.
