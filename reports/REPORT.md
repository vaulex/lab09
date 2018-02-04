### Лабораторная работа №6. Отчет.

## Задание на лабораторную работу:

- [ ] 1. Создать публичный репозиторий с названием **lab06** на сервисе **GitHub**
- [ ] 2. Выполнить инструкцию учебного материала
- [ ] 3. Ознакомиться со ссылками учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Выполнение работы.
	
В соответствии с последовательностью, определенной заданием на лабораторную работу, были выполнены следующие действия:
- [X] 1. Для успешного выполнения задания создан новый пустой репозиторий lab06 с лицензией MIT.
- [X] 2. Выполнена следующая последовательность команд:

## Tutorial
```ShellSession
$ export GITHUB_USERNAME=vaulex
$ export GITHUB_TOKEN=ke2f610e566b6bff59c6534ca260455c8e91baaa6
$ alias gsed=sed # for *-nix system
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab05 projects/lab06
$ cd projects/lab06
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab06
```

```ShellSession
$ mkdir tests
$ wget https://github.com/philsquared/Catch/releases/download/v1.9.3/catch.hpp -O tests/catch.hpp
$ cat > tests/main.cpp <<EOF
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
EOF
```

```ShellSession
$ gsed -i '/option(BUILD_EXAMPLES "Build examples" OFF)/a\
option(BUILD_TESTS "Build tests" OFF)
' CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF

if(BUILD_TESTS)
	enable_testing()
	file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
	add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
	target_link_libraries(check \${PROJECT_NAME} \${DEPENDS_LIBRARIES})
	add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes") 
endif()
EOF
```

```ShellSession
$ cat >> tests/test1.cpp <<EOF
#include "catch.hpp"
#include <print.hpp>

TEST_CASE("output values should match input values", "[file]") {
  std::string text = "hello";
  std::ofstream out("file.txt");
  
  print(text, out);
  out.close();
  
  std::string result;
  std::ifstream in("file.txt");
  in >> result;
  
  REQUIRE(result == text);
}
EOF
```

```ShellSession
$ cmake -H. -B_build -DBUILD_TESTS=ON
$ cmake --build _build
$ cmake --build _build --target test
```

```ShellSession
$ _build/check -s -r compact
$ cmake --build _build --target test -- ARGS=--verbose 
```

```ShellSession
$ gsed -i 's/lab05/lab06/g' README.md
$ gsed -i 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .travis.yml
$ gsed -i '/cmake --build _build --target install/a\
- cmake --build _build --target test -- ARGS=--verbose
' .travis.yml
```

```ShellSession
$ travis lint
```

```ShellSession
$ git add .
$ git commit -m"added tests"
$ git push origin master
```

```ShellSession
$ travis login --auto
$ travis enable
```

```ShellSession
$ mkdir artifacts
$ sleep 20s && gnome-screenshot --file artifacts/screenshot.png
# for macOS: $ screencapture -T 20 artifacts/screenshot.png
# open https://github.com/${GITHUB_USERNAME}/lab06
```
## Report

```ShellSession
$ popd
$ export LAB_NUMBER=06
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```


- [X] 3. Проведено ознакомление по приведенным ссылкам со следующими материалами по [Boost.Tests](http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/), [Google Test](https://github.com/google/googletest).
- [X] 4. Составлен отчет о работе в формате MD, ссылка отправлена в **slack**.

	
## Выводы:
В ходе проделанной работы проведена ознакомительная работа с механизмом билд-тестов, выполнен тест, результат записан в **file.txt**, получен снимок экрана.
