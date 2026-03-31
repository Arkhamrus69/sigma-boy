# Лабораторная работа №02
## Работа с Git и GitHub

---

## Часть 1.
1.1. Создание пустого репозитория на GitHub

На сайте github.com создан новый репозиторий с именем sigma-boy. Репозиторий создан пустым (без README, .gitignore, лицензии).

1.2. Настройка Git и создание локальной копии


```sh 
git config --global user.name "Arkhamrus69"
git config --global user.email "arkhamrus69@gmail.com"
cd ~/Рабочий\ стол/arkhamrus69@gmail.com/workspace
mkdir sigma-boy
cd sigma-boy
git init
```

<details> <summary>📋 Вывод git init</summary>
Initialized empty Git repository in /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/sigma-boy/.git/
</details>


1.3. Первый коммит (README.md)
```sh 
echo "# Sigma Boy Project" > README.md
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/Arkhamrus69/sigma-boy.git
git push -u origin main
```
<details> <summary>📋 Вывод git push</summary>
  <pre>
Username for 'https://github.com': Arkhamrus69
Password for 'https://Arkhamrus69@github.com': 
Перечисление объектов: 3, готово.
Подсчет объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 215 байтов | 215.00 КиБ/с, готово.
To https://github.com/Arkhamrus69/sigma-boy.git
 * [new branch]      main -> main
  </pre>
 </details>

1.4. Создание программы hello_world.cpp (плохой стиль)
```sh 
cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
EOF
git add hello_world.cpp
git commit -m "Add hello_world.cpp with bad style"
 ```
<details><summary>📄 Содержимое первой версии</summary>

 #include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
</details>

1.5. Изменение программы: добавление ввода имени пользователя
```sh 

cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from @" << name << endl;
    return 0;
}
EOF
git commit -am "имя"
```

Код изменён: теперь программа запрашивает имя пользователя и выводит приветствие.

Коммит выполнен с флагом -am, который автоматически добавляет изменения в отслеживаемых файлах (поэтому повторный git add не требуется).
<details> <summary>📄 Содержимое второй версии</summary>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from @" << name << endl;
    return 0;
}
</details>

<details> <summary>📋 Вывод git commit</summary>
[main 4f28f48] имя
 1 file changed, 5 insertions(+), 1 deletion(-)
</details>

1.6. Отправка изменений на GitHub и проверка истории
```sh
git push
```
Изменения отправлены в удалённый репозиторий.
<details> <summary>📋 Вывод git push</summary>
  <pre>
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
Запись объектов: 100% (3/3), 332 байта | 332.00 КиБ/с, готово.
To https://github.com/Arkhamrus69/sigma-boy.git
   2ab9149..4f28f48  main -> main
  </pre>
</details>

---
## Часть 2
2.1. Создание локальной ветки patch1
```sh
git checkout -b patch1
```
Создана новая ветка patch1 и выполнен переход на неё.


2.2. Исправление кода: удаление using namespace std
```sh
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
git add hello_world.cpp
git commit -m "-using namespace..."
```
2.3. Отправка ветки patch1 на GitHub
```sh
git push -u origin patch1
```
Ветка patch1 отправлена в удалённый репозиторий. После этого она доступна на GitHub.
<details> <summary>📋 Вывод git push</summary>
  <pre>
Username for 'https://github.com': Arkhamrus69
Password for 'https://Arkhamrus69@github.com': 
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 414 байтов | 414.00 КиБ/с, готово.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/Arkhamrus69/sigma-boy/pull/new/patch1
remote: 
To https://github.com/Arkhamrus69/sigma-boy.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.

  </pre>
</details>

2.4. Добавление комментариев в код (ветка patch1)
```sh
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

// Main function: entry point of the program
int main() {
    // Variable to store user's name
    std::string name;
    
    // Prompt user for input
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output greeting message
    std::cout << "Hello world from @" << name << std::endl;
    
    return 0;
}
EOF
```
2.5. Обновление ветки main после слияния
```sh
git checkout main
git pull origin main
```
<details> <summary>📋 Вывод git pull</summary>
<pre>
Переключились на ветку «main»
Эта ветка соответствует «origin/main».
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Распаковка объектов: 100% (1/1), 891 байт | 891.00 КиБ/с, готово.
Из https://github.com/Arkhamrus69/sigma-boy
 * branch            main       -> FETCH_HEAD
   4f28f48..26bae03  main       -> origin/main
Обновление 4f28f48..26bae03
Fast-forward
 hello_world.cpp | 16 +++++++++++-----
 1 file changed, 11 insertions(+), 5 deletions(-)
</pre>
</details>

2.6. Просмотр истории коммитов
```sh
git log --oneline
```
<details> <summary>📋 Вывод git log --oneline после слияния patch1</summary>
<pre>
26bae03 (HEAD -> main, origin/main) Merge pull request #1 from Arkhamrus69/patch1
5022667 (origin/patch1, patch1) Add comments to code
9d68a77 -using namespace...
4f28f48 имя
7111691 Add hello_world.cpp with bad style
2ab9149 first commit
</pre>
</details>

2.7. Удаление локальной ветки patch1
```sh
git branch -d patch1
```
2.8. Переключение на main и получение последних изменений

```sh
cd ~/Рабочий\ стол/arkhamrus69@gmail.com/workspace/sigma-boy
git checkout main
git pull origin main
```

## Часть 3.
3.1. Создание новой локальной ветки patch2
```sh
git checkout -b patch2
```
<details> <summary>📋 Вывод</summary>
text

Переключились на новую ветку «patch2»

</details>

3.2. Изменение code style с помощью утилиты clang-format
Установка clang-format
```sh
sudo apt update
sudo apt install clang-format -y
```
Применение форматирования
```sh
clang-format -style=Mozilla -i hello_world.cpp
```
3.3. commit, push, создание pull-request patch2 -> master
```sh
git add hello_world.cpp
git commit -m "Apply clang-format with Mozilla style"
git push -u origin patch2
```
<details> <summary>📋 Вывод коммита и push</summary>
<pre>
[patch2 3a7b5f6] Apply clang-format with Mozilla style
 1 file changed, 14 insertions(+), 12 deletions(-)
Username for 'https://github.com': Arkhamrus69
Password for 'https://Arkhamrus69@github.com': 
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
Запись объектов: 100% (3/3), 426 байтов | 426.00 КиБ/с, готово.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 loc
</pre>
</details>

3.4. В ветке master в удалённом репозитории измените комментарии






```sh
git checkout main

cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

// Главная функция: точка входа в программу
int main()
{
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия
    std::cout << "Hello world from @" << name << std::endl;

    return 0;
}
EOF



git add hello_world.cpp
git commit -m "Change comments to Russian language"
git push


```
<details> <summary>📄 Файл после изменения комментариев</summary>
#include <iostream>
#include <string>

// Главная функция: точка входа в программу
int main()
{
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия
    std::cout << "Hello world from @" << name << std::endl;

    return 0;
}

</details>

3.5. Убедиться, что в pull-request появились конфликты

После изменения комментариев в ветке main страница pull request на GitHub обновилась, и появилось сообщение:
«This branch has conflicts that must be resolved».

3.6. Локально выполнить pull + rebase
```sh
git checkout patch2
git fetch origin
git rebase origin/main
```

<details> <summary>⚠️ Сообщение о конфликте</summary>
<pre>
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply ... Apply clang-format with Mozilla style
</pre>
</details>

```sh
# После исправления конфликта
git add hello_world.cpp
git rebase --continue
```
3.7. Сделать force push в ветку patch2
```sh
git push --force origin patch2
```
Что делает команда: Принудительно отправляет изменённую (после rebase) ветку patch2 в удалённый репозиторий, перезаписывая её историю.
<details> <summary>📋 Вывод force push</summary>


+ 3a7b5f6...ea50cfb patch2 -> patch2 (forced update)

</details>
На GitHub нажата кнопка «Merge pull request», затем «Confirm merge». Ветка patch2 на GitHub удалена.

Удаление ветки patch2:
```sh
git branch -d patch2
git push origin --delete patch2
git remote prune origin
git branch -a (проверка на отсутствие веток)
```


Умни чат-гпт: "git remote prune origin"
Что делает: Удаляет локальные ссылки на удалённые ветки, которые больше не существуют на GitHub (например, origin/patch1, origin/patch2). Это полезно, чтобы git branch -a не показывал мусор.


3.8. Локальное обновление main

```sh
git checkout main
git pull origin main
git log --oneline --graph
```
<details> <summary>📋 Финальная история коммитов</summary>
<pre>

* ea50cfb (HEAD -> main, origin/main) Change comments to Russian language
*   26bae03 Merge pull request #1 from Arkhamrus69/patch1
|\  
| * 5022667 Add comments to code
| * 9d68a77 -using namespace...
|/  
* 4f28f48 имя
* 7111691 Add hello_world.cpp with bad style
* 2ab9149 first commit
</pre>
</details>


