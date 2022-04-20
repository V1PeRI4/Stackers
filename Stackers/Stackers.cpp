#include <iostream>
#include <cstring>

using namespace std;

struct Stack {
    int info;
    Stack* next;
} *beginStack;


Stack* InStack(Stack* p, int in) {
    Stack* t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}


void viewStack(Stack* p) {
    Stack* t = p;
    while (t != NULL) {
        cout << " " << t->info << endl;
        t = t->next;
    }
}


void delStack(Stack** p) {
    while (*p != NULL) {
        Stack *t = *p;
        *p = (*p)->next;
            delete t;
    }
}

void Sort_p(Stack* p)
{
    Stack* t = NULL, * t1;
    int r;

    do
    {
        for (t1 = p; t1->next != t; t1 = t1->next)

            if (t1->info > t1->next->info)
            {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int i, in, n, command;

    while (true) {
        system("cls");

        cout << "\n1. Создать стэк."
            "\n2. Добавить элементы в стэк."
            "\n3. Посмотреть стэк."
            "\n4. Отсортировать стэк."
            "\n5. Удалить стэк."
            "\n0. Выход.\n" << endl;
        cin >> command;
        switch (command) {
        default:
            cout << "Неизвестная команда" << endl;
            break;

        case 1: case 2:

            if (command == 1 && beginStack != NULL) {
                cout << "Очистка памяти" << endl;

                system("pause");
                break;
            }
            cout << "Введите кол-во элементов: ";
            cin >> n;
            for (i = 1; i <= n; i++) {
                in = rand() % 100 - 60;
                beginStack = InStack(beginStack, in);
            }
            if (command == 1)
                cout << "Создано " << n << " эл." << endl;
            else cout << "Добавлено " << n << " эл." << endl;

            system("pause");
            break;

        case 3:
            if (!beginStack) {
                cout << "стэк пуст!" << endl;

                system("pause");
                break;
            }

            cout << "\n---Stack---" << endl;
            viewStack(beginStack);

            system("pause");
            break;

        case 4:
            if (!beginStack) {
                cout << " пуст!" << endl;

                system("pause");
                break;
            }

            Sort_p(beginStack);

            system("pause");
            break;

        case 5:
            delStack(&beginStack);
            cout << "Память чиста!" << endl;

            system("pause");
            break;

        case 0:
            if (beginStack != NULL)
                delStack(&beginStack);

            system("pause");
            return 0;
        }
    }


}

//sus
