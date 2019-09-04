#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QTextStream>
#include<bits/stdc++.h>
const char delim=';';

class dictionary{
public:


    struct trienode{
        struct trienode *child[26];
        std::string meaning;
        bool isword;
    };

    struct trienode *root = NULL;
    dictionary(){
        root = new trienode;
        for(int i = 0; i < 26; i++)
            root->child[i] = NULL;
        root->isword = false;
    }

    void insert(std::string key, std::string meaning){
        struct trienode *node = root;
        for(int i = 0; i < key.size(); i++){
            unsigned int ind = static_cast<unsigned int>(key[i]) - 97;
            if(node->child[ind] == NULL)
                node->child[ind] = new trienode();
            node = node->child[ind];
        }
        node->meaning = meaning;
        node->isword = true;
    }
    void read(){
        QFile file("/home/priyanshu/DS_LABS/L4_Priyanshu_Garg_18114058/L4_P1_input.csv");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                            return;
                    QTextStream in(&file);
                        while (!in.atEnd()) {
                            QString Qline = in.readLine();
                            std::string line = Qline.toUtf8().constData();
                            std::string a,b;
                            std::stringstream row(line);
                            std::getline(row,a,delim);
                            std::getline(row,b,delim);
                            insert(a,b);
    }
    }
    std::string search(std::string key){
        struct trienode *node = root;
        if(!node)
            return "Word not found";

        for(int i = 0; i < key.size(); i++){
            int ind = key[i]-'A';
            node = node->child[ind];
            if(!node)
                return "Word not found";
        }
        if(node->isword)
            return node->meaning;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    trienode *root = new trienode();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dictionary dict;
};

#endif // MAINWINDOW_H
