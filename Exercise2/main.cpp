
#include <iostream>
#include <fstream> // per lavorare con i file
#include <iomanip>  //  serve per il controllo della precisione


//funzione per mappare i valori da [1,5] a [-1,2]
//primo double indica che output sara un double mentre il secondo mi dice che i valori x presi in input sono double 
// funzione esterna mappa al main per poi la richiamo
double mappa (double x) {            
    
    return -1.0 + (x - 1.0)*(3.0/4.0); // applico la formula di cambio base, 3.0 e 4.0 sono double
                                       //questa scrittura è equivalente a calcolare (3.0/4.0)*x - (7.0/4.0)
}


int main() {
    // Apertura del file di input e output.std::ifstream apre in lettura. std::ofstream apre in scrittura
    std::ifstream input_file("data.txt");
    std::ofstream output_file("result.txt");

    if (input_file.fail()) {   //ciclo per controllare eventuali errori nell'apertura file data.txt
       std::cerr << "Errore nell'aprire il file di input!" << std::endl; 
    }
    if (output_file.fail()) {   //ciclo per controllare eventuali errori nell'apertura file result.txt
        std::cerr << "Errore nell'aprire il file di output!" << std::endl;
        return 1;
    }

    
    
    
    output_file << "# N Mean\n";  //questo serve per definire la prima riga del file di output come da richiesta dell'esercizio


    double valore;  // Variabile per memorizzare ogni valore letto
    double somma_cumulativa = 0.0;  // inizializzo la somma cumulativa
    int i = 0;  // Conta il numero di valori letti

    // Leggo i valori dal file e calcola la media cumulativa
    while (input_file >> valore) {
        // Mappa il valore dell'intervallo [1, 5] a [-1, 2]
        double val_mappato = mappa(valore);
        
        // Aggiungo il valore mappato alla somma cumulativa
        somma_cumulativa =somma_cumulativa + val_mappato;
        
        // Incrementa il contatore
        i=i + 1;
        
        // Calcolo la media dei primi i valori mappati
        double media = somma_cumulativa / i;

        // Scrive nel file di output il numero di valori e la loro media
        output_file << i << " " << std::scientific  << std::setprecision(16) << media << "\n";
    
    }

    // Chiusura dei file (input e output) aperti a inizio codice
    input_file.close();
    output_file.close();

    std::cout << "Il codice è completo e i risultati sono stati salvati in result.txt" << std::endl; //stampa a terminale


    return 0;
}

   