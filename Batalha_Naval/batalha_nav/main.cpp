#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <cstdlib>
#include <ctime>
#include <QLabel>
#include <vector>
#include <iostream>

class TabuleiroJogador : public QWidget {
public:
    TabuleiroJogador(QWidget* parent = nullptr) : QWidget(parent) {
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    //gera a matriz de botôes
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            QPushButton* button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(button, &QPushButton::clicked, this, [this, button]() {
                 onButtonClicked(button);
            });
            gridLayout->addWidget(button, i, j);
            buttons[i][j] = button;
        }
    }
  }

private:
    int contadorCliques; // Contador de barcos
    int score =0;//Pontuacao
    QGridLayout* gridLayout;
    QPushButton* buttons[10][10];

    void onButtonClicked(QPushButton* button) {
        //Escolhe 3 posições para os barcos
        if (contadorCliques < 3) {
              button->setStyleSheet("background-color: gray");
              contadorCliques++;
          }
        //Começa o jogo, caso atinja a agua fica azul caso o barco vermelho
        else if (button->styleSheet().isEmpty()) {
              button->setStyleSheet("background-color: blue");
          }
        else if (button->styleSheet() == "background-color: gray") {
              button->setStyleSheet("background-color: red");
              score++;

              //Declara Vitória para o Jogador 2
              if (score == 3) {
                 QApplication::closeAllWindows();
                 QWidget* vitoriaWindow = new QWidget;
                 QVBoxLayout* layout = new QVBoxLayout(vitoriaWindow);
                 QLabel* label = new QLabel("Vitoria do Jogador 2", vitoriaWindow);
                 QFont font = label->font();
                 font.setPointSize(30);
                 label->setFont(font);
                 label->setAlignment(Qt::AlignCenter);
                 layout->addWidget(label);
                 vitoriaWindow->setLayout(layout);
                 vitoriaWindow->showMaximized();
                 vitoriaWindow->setAttribute(Qt::WA_DeleteOnClose);
              }
          }
      }

  };
class TabuleiroAdversario : public QWidget {
public:
    TabuleiroAdversario(QWidget* parent = nullptr) : QWidget(parent) {
    gridLayout = new QGridLayout(this);

    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    //gera a matriz de botôes
    for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    QPushButton* button = new QPushButton(this);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    connect(button, &QPushButton::clicked, this, [this, button]() {
                         onButtonClicked(button);
                    });
                    gridLayout->addWidget(button, i, j);
                    buttons[i][j] = button;
        }
    }

}

private:
    int contadorCliques; // Contador de cliques realizados
    int score=0;//Pontuacao
    QGridLayout* gridLayout;
    QPushButton* buttons[10][10];

    void onButtonClicked(QPushButton* button) {
          //Escolhe 3 posições para os barcos
        if (contadorCliques < 3) {
              button->setStyleSheet("background-color: gray");
              contadorCliques++;
          }
        //Começa o jogo, caso atinja a agua fica azul caso o barco vermelho
        else if (button->styleSheet().isEmpty()) {
              button->setStyleSheet("background-color: blue");
          }
        else if (button->styleSheet() == "background-color: gray") {
              button->setStyleSheet("background-color: red");
              score++;

              //Declara vitória para jogador 1
              if (score == 3) {
                 QApplication::closeAllWindows();
                 QWidget* vitoriaWindow = new QWidget;
                 QVBoxLayout* layout = new QVBoxLayout(vitoriaWindow);
                 QLabel* label = new QLabel("Vitoria do Jogador 1", vitoriaWindow);
                 QFont font = label->font();
                 font.setPointSize(30);
                 label->setFont(font);
                 label->setAlignment(Qt::AlignCenter);
                 layout->addWidget(label);
                 vitoriaWindow->setLayout(layout);
                 vitoriaWindow->showMaximized();
                 vitoriaWindow->setAttribute(Qt::WA_DeleteOnClose);
          }
        }
      }

  };

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);


    // Janela do Tabuleiro do Jogador 1
     TabuleiroJogador tabuleiroJogador;
     QVBoxLayout* tabuleiroJogadorLayout = new QVBoxLayout;
     QLabel* tabuleiroJogadorLabel = new QLabel("Tabuleiro do Jogador 1");
     tabuleiroJogadorLabel->setAlignment(Qt::AlignCenter);
     tabuleiroJogadorLayout->addWidget(tabuleiroJogadorLabel);
     tabuleiroJogadorLayout->addWidget(&tabuleiroJogador);
     QWidget tabuleiroJogadorWindow;
     tabuleiroJogadorWindow.setLayout(tabuleiroJogadorLayout);
     tabuleiroJogadorWindow.setWindowTitle("Tabuleiro do Jogador 1");
     tabuleiroJogadorWindow.show();

     // Janela do Tabuleiro do Jogador 2
     TabuleiroAdversario tabuleiroAdversario(&tabuleiroJogador);
     QVBoxLayout* tabuleiroAdversarioLayout = new QVBoxLayout;
     QLabel* tabuleiroAdversarioLabel = new QLabel("Tabuleiro do Jogador 2");
     tabuleiroAdversarioLabel->setAlignment(Qt::AlignCenter);
     tabuleiroAdversarioLayout->addWidget(tabuleiroAdversarioLabel);
     tabuleiroAdversarioLayout->addWidget(&tabuleiroAdversario);
     QWidget tabuleiroAdversarioWindow;
     tabuleiroAdversarioWindow.setLayout(tabuleiroAdversarioLayout);
     tabuleiroAdversarioWindow.setWindowTitle("Tabuleiro do Jogador 2");
     tabuleiroAdversarioWindow.show();

    return app.exec();
}
