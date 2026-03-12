
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QListWidget> // Nou: Pentru istoricul numerelor

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget fereastra;
    fereastra.setWindowTitle("Verificator Par/Impar PRO");
    fereastra.resize(350, 450); // Am făcut fereastra puțin mai mare

    // 1. Stilizarea ferestrei folosind QSS (asemănător cu CSS-ul din web)
    // R"( ... )" ne permite să scriem text pe mai multe rânduri în C++
    fereastra.setStyleSheet(R"(
        QWidget {
            background-color: #2b2b2b; /* Fundal închis (Dark Mode) */
            color: #f1f1f1; /* Text deschis la culoare */
            font-family: 'Segoe UI', Helvetica, Arial, sans-serif;
            font-size: 14px;
        }
        QLineEdit {
            background-color: #3c3f41;
            border: 1px solid #555555;
            border-radius: 5px;
            padding: 8px;
        }
        QPushButton {
            background-color: #4CAF50; /* Verde frumos */
            color: white;
            border: none;
            border-radius: 5px;
            padding: 10px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #45a049; /* Verde mai închis când pui mouse-ul */
        }
        QPushButton:pressed {
            background-color: #3d8b40; /* Când dai click */
        }
        QListWidget {
            background-color: #3c3f41;
            border: 1px solid #555555;
            border-radius: 5px;
            padding: 5px;
        }
    )");

    QVBoxLayout *layout = new QVBoxLayout(&fereastra);

    // 2. Creăm elementele interfeței
    QLineEdit *campIntroducere = new QLineEdit();
    campIntroducere->setPlaceholderText("Introdu un număr și apasă Enter...");

    QPushButton *butonVerificare = new QPushButton("Verifică Numărul");

    QLabel *mesajRezultat = new QLabel("Aștept un număr...");
    mesajRezultat->setAlignment(Qt::AlignCenter); // Centrăm textul
    // Suprascriem stilul doar pentru acest text ca să iasă în evidență
    mesajRezultat->setStyleSheet("font-size: 16px; font-weight: bold; color: #ffeb3b; margin: 10px 0;");

    QLabel *etichetaIstoric = new QLabel("Istoric verificări:");
    QListWidget *listaIstoric = new QListWidget(); // Aici vom pune istoricul

    // Adăugăm totul în fereastră
    layout->addWidget(campIntroducere);
    layout->addWidget(butonVerificare);
    layout->addWidget(mesajRezultat);
    layout->addWidget(etichetaIstoric);
    layout->addWidget(listaIstoric);

    // 3. Extragem logica într-o "funcție anonimă" (lambda) ca să o refolosim
    auto actiuneVerificare = [&]() {
        bool esteNumarValid;
        QString textIntrodus = campIntroducere->text();
        
        if (textIntrodus.isEmpty()) return; // Dacă nu a scris nimic, nu facem nimic

        int numar = textIntrodus.toInt(&esteNumarValid);

        if (esteNumarValid) {
            QString rezultat = (numar % 2 == 0) ? "PAR" : "IMPAR";
            mesajRezultat->setText("Rezultat: " + QString::number(numar) + " este " + rezultat);
            
            // Adăugăm în lista de istoric
            listaIstoric->addItem(QString::number(numar) + " -> " + rezultat);
            // Defilăm lista automată la ultimul element
            listaIstoric->scrollToBottom(); 
        } else {
            mesajRezultat->setText("Eroare: '" + textIntrodus + "' nu e număr!");
        }

        // După verificare, golim câmpul și punem cursorul înapoi în el
        campIntroducere->clear();
        campIntroducere->setFocus();
    };

    // 4. Conectăm logica atât la click pe buton, cât și la apăsarea tastei Enter
    QObject::connect(butonVerificare, &QPushButton::clicked, actiuneVerificare);
    QObject::connect(campIntroducere, &QLineEdit::returnPressed, actiuneVerificare);

    fereastra.show();
    return app.exec();
}