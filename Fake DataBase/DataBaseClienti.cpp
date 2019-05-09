#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<new>
#include<ctype.h>
#include <sstream>
using namespace std;

string nome, cognome, natoA, natoIl, residenteA, residenteVia, documentoT,documentoN, rilasciatoDa,
  rilasciatoIl, nLicenza, categoria, mezzoN, targa, modello,/**/mi , nM, cM, natoM,dataM , KMA;
int _q;

void Accenti(string& _str){
	for(int i = 0; i < _str.length(); i++){
		switch((int)_str[i]){
			case (-107): _str[i] = 'ò'; break;
			case (-123): _str[i] = 'à'; break;
			case (-118): _str[i] = 'è'; break;
			case (-126): _str[i] = 'é'; break;
			case (-105): _str[i] = 'ù'; break;
			case (-115): _str[i] = 'ì'; break;
		}
	}
}

void InfoCliente(char _pn){ //Prendere le informazioni del cliente
	cout << "Nome: ";
	getline(cin,nome);
	Accenti(nome);
	cout << "Cognome: ";
	getline(cin,cognome);
	Accenti(cognome);
	cout << "Nato a: ";
	getline(cin,natoA);
	Accenti(natoA);
	cout << "Nato il: ";
	getline(cin,natoIl);
	Accenti(natoIl);
	cout << "Residente a: ";
	getline(cin,residenteA);
	Accenti(residenteA);
	cout << "Residente in via: ";
	getline(cin,residenteVia);
	Accenti(residenteVia);
	cout << "Tipo documento: ";
	getline(cin,documentoT);
	Accenti(documentoT);
	cout << "Documento numero: ";
	getline(cin,documentoN);
	Accenti(documentoN);
	cout << "Rilasciato da: ";
	getline(cin,rilasciatoDa);
	Accenti(rilasciatoDa);
	cout << "Rilasciato il: ";
	getline(cin,rilasciatoIl);
	Accenti(rilasciatoIl);
	cout << "Numero licenza: ";
	getline(cin,nLicenza);
	Accenti(nLicenza);
	cout << "Categoria: ";
	getline(cin,categoria);
	Accenti(categoria);
	if(_pn == 'p' or _pn == 'P'){
		cout << "Mezzo numero: ";
		getline(cin,mezzoN);
		Accenti(mezzoN);
		cout << "Targa: ";
		getline(cin,targa);
		Accenti(targa);
		cout << "Modello: ";
		getline(cin,modello);
		Accenti(modello);
	}else if(_pn == 'n' or _pn == 'N'){
		mezzoN=""; targa=""; modello="";
	}
}

void InfoMinorenne(){ //Prendere le informazioni del minorenne
	cout << "Nome del minorenne: ";
	getline(cin,nM);
	Accenti(nM);
	cout << "Cognome del minorenne: ";
	getline(cin,cM);
	Accenti(cM);
	cout << "Luogo di nascita: ";
	getline(cin,natoM);
	Accenti(natoM);
	cout << "Data di nascita: ";
	getline(cin,dataM);
	Accenti(dataM);
}

void SaveInfo(){ //Salvere le informazioni del cliente nel Data Base
	fstream SaveFile("DataBaseClienti/DataBase.txt",ios::app);
	SaveFile << nome << endl << cognome << endl  << natoA << endl
			 << natoIl << endl << residenteA << endl << residenteVia<< endl
			 << documentoT <<endl << documentoN<< endl
			 <<rilasciatoDa<< endl << rilasciatoIl<< endl
			 << nLicenza<< endl << categoria << endl	
			 << mezzoN << endl
			<< targa << endl
			<< modello << endl;
	SaveFile << mi << endl;
	if(mi == "1")
		SaveFile << nM << endl << cM << endl << natoM << endl << dataM << endl;
	else if(mi=="0") {
		nM=""; cM=""; natoM=""; dataM="";
	}	
	SaveFile.close();
}

int* getData() {
	time_t data = time(NULL);//data salvata in data
	tm* tempo = localtime(&data);//inizializza struttura tm
	int* times = new int[3];//array che contiene gm, m, a
	times[0] = tempo->tm_mday;//giorno mese
	times[1] = tempo->tm_mon;//mese
	times[2] = tempo->tm_year;//anno
	return times;
}

void FacPrivato(){
	ofstream SaveFile("DataBaseClienti/Stampa.doc");
	switch(KMA[0]){
		case 'k':
		case 'K':{
			SaveFile <<"PISTA DEL SOLE"<<endl
					<< "C.da Dominici - Villasmundo            Kart n. " << mezzoN <<endl
					<<"96010 - Melilli" << endl<< endl;
			break;
		}
		case 'm':
		case 'M':{
			SaveFile <<"PISTA DEL SOLE                         Moto n. " << mezzoN <<"  Targa:  " << targa <<endl
					<< "C.da Dominici - Villasmundo            Modello:   " << modello <<endl
					<<"96010 - Melilli" << endl<< endl;
			break;
		}
		case 'a':
		case 'A':{
			SaveFile <<"PISTA DEL SOLE                          Auto n. " << mezzoN <<"  Targa:  " << targa <<endl
					<< "C.da Dominici - Villasmundo             Modello:  " << modello <<endl
					<< "96010 - Melilli" << endl<< endl;
			break;
		}
	}
	
	SaveFile << "Il sottoscritto     "<< nome << " " << cognome <<"    nato a    " << natoA
			<< "    il     " << natoIl << "     . Residente a     " << residenteA << "    via    " << residenteVia 
			<< "    titolare del documento di riconoscimenti tipo " << documentoT << " N.   "<<documentoN << "  rilasciato da   " << rilasciatoDa 
			<< "    il    " << rilasciatoIl <<". Pilota ";
			switch(KMA[0]){
				case 'k':
				case 'K':{SaveFile << "kart ";break;}
				case 'm':
				case 'M':{SaveFile << "moto ";break;}
				case 'a':
				case 'A':{SaveFile << "auto ";break;
				}
			}
	SaveFile << "n. licenza    " << nLicenza << "    categoria    " << categoria <<"   ." << endl << endl
			<<  "                               DICHIARA" << endl
			<< "ed accetta quanto segue:" << endl
			<< "1) di essere in perfetta condizione psicofisica e di non avere alcuna patologia che possa impedire o rendere"
			<< " imperfetto l'utilizzo e la guida del kart;" << endl
			<< "2) che il proprio mezzo è omologato idoneo alle prove in pista e perfettamente revisionato ed in ottimo"
			<< " stato d'uso;" << endl
			<< "3) di assumersi tutte le responsabilità in sede sia civile che penale che dovessero derivare da incidenti dolosi "
			<< "colposi o accidentali in occasione dell'utilizzo della pista sin da ora, dichiarando ed accettando di fare "
			<< "prontezza di eventuale obbligo di risarcimento danni anche verso terzi;" << endl
			<< "4) di aver preso visione del regolamento e del circuito;" << endl
			<< "5) (in caso di pilota minorenne) che esercita la patria potestà sul "; 	
			switch(mi[0]){
				case '0':{
					SaveFile << endl << "minore_______________________________________ nato a_____________________ " << endl
							<< "il___________________ e che pertanto si assume ogni responsabilità sul comportamento del minore "
							<< "durante le prove in pista." << endl << endl;	
					break;
				}
				case '1':{
					SaveFile << "minore     " << nM << " " << cM << "     nato a     " << natoM 
							<< "   il    " << dataM << "    e che pertanto si assume ogni responsabilità sul comportamento "
							<< "del minore durante le prove in pista." << endl << endl;
					break;
				}
			}
			SaveFile<< "Villasmundo,il  "<< getData()[0] << "/" << (getData()[1] + 1) << "/" << (getData()[2] + 1900) << endl << endl
			        << "                               In fede _____________________________" << endl << endl 
					<< "                                 REGOLAMENTO" << endl << endl
					<<  "1) L'ingresso in pista è consentito esclusivamente a personale autorizzato e ai conduttori:" << endl
   					<<  "  a) che abbiano effettuato l'iscrizione e firmato il foglio di responsabilità;"<< endl
  					<<  "  b) che siano in completa tenuta di gara (casco integrale, tuta, guanti, scarpette);" << endl
  					<<  "  c) con kart fornito di regolare identificazione;" << endl
					<<  "2) I conduttori devono avere l'età prescritta per condurre i rispettivi karts;" << endl
					<<  "3) non è consentito provare karts nella zona box;" << endl
					<<  "4) la direzione si riserva di stabilire dei turni di ingresso in pista per classe e categoria;" << endl
					<<  "5) la spinta per rimettere in moto il kart fermatosi in pista può essere effettuata esclusivamente da parte del personale "
					<<  "espressamente autorizzato dalla DIREZIONE;" << endl
					<<  "6) le riparazioni con l'aiuto dei meccanici sono consentite soltanto nella zona box;" << endl
					<<  "DISPOSIZIONI FINALI: per quanto non espressamente indicato nel presente regolamento si rinvia al R.N.K." << endl << endl << endl
					<<  "                      Per accettazione __________________________";
	SaveFile.close();
}

void FacNoleggio(){
	ofstream SaveFile("DataBaseClienti/Stampa.doc");
	SaveFile<<"                             PISTA DEL SOLE"<<endl
		<<"                     www.pistadelsole.com – 3203583239" << endl
		<<"               C.da Dominici, 96010 Villasmundo – Melilli (SR)" << endl
		<<"                 Tratto autostradale Augusta – Villasmundo"<<endl<<endl

		<<"Il sottoscritto     "<<nome<<" "<<cognome<<"     nato a     "<< natoA <<  "     il     "<< natoIl 
		<<"     e residente a     "  << residenteA <<"     via     " << residenteVia<<"     documento tipo     " 
		<< documentoT<<"     n°     " <<documentoN<<"     rilasciato il     "<< rilasciatoIl << "    da     " << rilasciatoDa<<" ." << endl << endl
		<<"                      NEL NOLEGGIARE UN GO-KART DICHIARA: "<<endl << endl
		<<"• Di verificare prima della partenza l’efficienza del sistema frenante e sterzante del mezzo noleggiato e di segnalare qualsiasi anomalia al personale addetto in pista;"<<endl
		<<"• Di tenere il casco sempre allacciato;"<<endl
		<<"• Di essere a conoscenza che è proibito gareggiare tra noleggianti in particolar modo tra amici, mantenendo sempre una distanza di sicurezza fra i go-kart;"<<endl
		<<"• Di effettuare i sorpassi solo sui tratti di rettilineo e non nelle curve;"<<endl
		<<"• Di assumersi ogni responsabilità per eventuali danni provocati o subiti e di sollevare da qualsiasi responsabilità la Direzione e gestione della pista;"<<endl
		<<"• Di risarcire eventuali danni causati dalla propria incuria;"<<endl;
	switch(mi[0]){
		case '0':{
			SaveFile <<"• (in caso di pilota minorenne) che esercita la patria potestà sul minore" << endl
					 <<	"_____________________________ nato a_______________ " << endl
					 <<	"il_________________________." << endl << endl << endl;		 
			break;	
		}
		case '1':{
			SaveFile <<"• (in caso di pilota minorenne) che esercita la patria potestà sul minore    " 
			<< nM <<" "<< cM << "    nato a    "<< natoM << "    il    " << dataM << "  ." << endl << endl << endl;
			break;
		}
	}
	SaveFile << "Villasmundo,il  " << getData()[0] << "/" << (getData()[1] + 1) << "/" << (getData()[2] + 1900) << endl << endl
					 << "                                           IN FEDE" << endl << endl
					 << "	                           ______________________________";	
	SaveFile.close();
}

bool Search(string _nome,string _cognome){
	Accenti(_nome); Accenti(_cognome);
	string nomeTemp="", cognomeTemp="";
	for(int i=0;i<_nome.length();i++) if(_nome[i]!=' ') nomeTemp += _nome[i];
	for(int i=0;i<_cognome.length();i++) if(_cognome[i]!=' ') cognomeTemp += _cognome[i];
	for(int i=0; i<nomeTemp.length(); i++) nomeTemp[i] = toupper(nomeTemp[i]);
	for(int i=0; i<cognomeTemp.length(); i++) cognomeTemp[i] = toupper(cognomeTemp[i]);
		
	ifstream OpenFile("DataBaseClienti/DataBase.txt"); //Ricerca cliente nel Data Base
	string dep1="",dep2="",temp[20][30];
	for(int j = 0; j < 30; j++)
		for(int i = 0; i < 20; i++)
			temp[i][j]="";
	int cont = 0;
		do{
			dep1="",dep2="";
			getline(OpenFile,temp[0][cont]);
			getline(OpenFile,temp[1][cont]);
			for(int i=0;i<temp[0][cont].length();i++) if(temp[0][cont][i]!=' ') dep1 += temp[0][cont][i];
			for(int i=0;i<temp[1][cont].length();i++) if(temp[1][cont][i]!=' ') dep2 += temp[1][cont][i];
			for(int i=0; i<dep1.length(); i++) dep1[i] = toupper(dep1[i]);
			for(int i=0; i<dep2.length(); i++) dep2[i] = toupper(dep2[i]);
			for(int i = 2; i < 16; i++) getline(OpenFile,temp[i][cont]);
			if(temp[15][cont]=="1"){getline(OpenFile,temp[16][cont]);getline(OpenFile,temp[17][cont]);
					getline(OpenFile,temp[18][cont]);getline(OpenFile,temp[19][cont]);}
			else if(temp[15][cont]=="0"){
				nM=""; cM=""; natoM=""; dataM="";
			}
			if(dep1+" "+dep2 == nomeTemp+" "+cognomeTemp) cont++;
		}while(!OpenFile.eof());
		OpenFile.close();
		int q=0;
		if(cont>=1){
			if(cont==1){
				cout << "Cliente trovato!" << endl;
				q=1;
			} else {
				cout << endl << "Sono stati trovati "<< cont << " clienti!" << endl << endl;
				for(int j = 0; j < cont; j++){ // Stampa dei clienti trovati
					cout << j+1 << ") ";
					if(temp[15][j]=="0")
						for(int i = 0; i < 15; i++) 
							cout << temp[i][j] << "    ";
					else if(temp[15][j]=="1")
						for(int i = 0; i < 20; i++){
							if(i!=15) cout << temp[i][j] << "    ";
							else if(i==15) cout << endl << "   MINORENNE: ";
						}
					cout << endl <<"-----------------------------------------------------------------" << endl;	
				}
				 string risp;
				do{
					cout << "Quale cliente considerare?(numero): ";
					getline(cin,risp);
					stringstream ss(risp);
					ss >> q;
				}while(q > cont or q < 1);
			}
			_q=q;
			nome = temp[0][q-1]; cognome = temp[1][q-1]; natoA = temp[2][q-1]; natoIl = temp[3][q-1]; 
			residenteA = temp[4][q-1]; residenteVia = temp[5][q-1]; documentoT = temp[6][q-1]; 
			documentoN = temp[7][q-1]; rilasciatoDa = temp[8][q-1]; rilasciatoIl = temp[9][q-1];
			nLicenza = temp[10][q-1]; categoria = temp[11][q-1]; mezzoN = temp[12][q-1]; targa = temp[13][q-1];
			modello = temp[14][q-1]; mi = temp[15][q-1]; nM = temp[16][q-1]; cM = temp[17][q-1]; natoM = temp[18][q-1];
			dataM = temp[19][q-1];	
			
			return true;
		}
		else{
			cout << "Cliente non trovato! " << endl;
			return false;
		}
}

void Visualizza(){
	string temp;
	ifstream OpenFile("DataBaseClienti/DataBase.txt");
	ofstream SaveFile("DataBaseClienti/Visualizza.txt");
	int cont = 0;
	while(!OpenFile.eof()){
		getline(OpenFile,temp);
		if(temp != ""){
			cont++;
			SaveFile << cont << ") ";
			SaveFile << temp << "    ";
			for(int i = 0; i < 14; i++){
				getline(OpenFile,temp);
				SaveFile << temp << "    ";
			}
			getline(OpenFile,temp);
			if(temp == "1"){
				SaveFile << endl << "   MINORENNE: ";
				for(int i = 0; i < 4; i++){
					getline(OpenFile,temp);
					SaveFile << temp << "    ";
				}
			} 
			SaveFile << endl <<" --------------------------------------------------------------------"
					<< "---------------------------------------------------------------------------"<<endl;	
		}
	}
	
	OpenFile.close(); SaveFile.close();
	system("start DataBaseClienti/Visualizza.txt");
}

void Aggiungi(){
	string pn;
	do{ // Chiede se il cliente è privato o noleggiante
		cout << "Privato o noleggiante?: ";
		getline(cin,pn);
	}while(pn!="p" and pn!="P" and pn!="n" and pn!="N");
	InfoCliente(pn[0]);
	do{
		cout<<"C'e' un minorenne?: ";
		getline(cin,mi);
	}while(mi!="n" and mi!="N" and mi!="s" and mi!="S");
	if(mi=="s" or mi == "S"){
		mi = "1";
		InfoMinorenne();
	} else mi = "0";
	SaveInfo();
}

void Modifica(){
	string nomeElim, cognomeElim, nomeTemp="", cognomeTemp="", dep1="", dep2="", temp[20];
	string temp2[20]={"Nome:  ", "Cognome:  ", "Nato a:  ", "Nato il:  ", "Residente a: ", "Residente in via: ",
	"Documento tipo: ","Documento N.: ", "Rilasciato da: ", "Rilasciato il: ", "Numero licenza: ", "Categoria:  ", 
	"Mezzo numero: ", "Targa: ", "Modello: ", "Minorenne?: ",
	 "Nome Minore: ", "Cognome Minore: ", "Minore nato a: ", "Minore nato il: "};
	do{
		cout << "Nome del cliente da modificare: ";
		getline(cin,nomeElim);
		Accenti(nomeElim);
		cout << "Cognome del cliente da modificare: ";
		getline(cin,cognomeElim);
		Accenti(cognomeElim);
		//if(!Search(nomeElim,cognomeElim)) cout << "Cliente non trovato! " << endl;
	}while(!Search(nomeElim,cognomeElim));
	/*da migliorere tutta la parte qui sotto è sistemabile/rimovibile*/
	for(int i=0;i<nomeElim.length();i++) if(nomeElim[i]!=' ') nomeTemp += nomeElim[i];
	for(int i=0;i<cognomeElim.length();i++) if(cognomeElim[i]!=' ') cognomeTemp += cognomeElim[i];
	for(int i=0; i<nomeTemp.length(); i++) nomeTemp[i] = toupper(nomeTemp[i]);
	for(int i=0; i<cognomeTemp.length(); i++) cognomeTemp[i] = toupper(cognomeTemp[i]);
	int cont=1;
	ifstream OpenFile("DataBaseClienti/DataBase.txt");
	ofstream SaveFile("DataBaseClienti/Copia.txt");
	while(!OpenFile.eof()){
		for(int i = 0; i < 16; i++) getline(OpenFile,temp[i]);
		if(temp[15]=="1") for(int i = 16; i < 20; i++) getline(OpenFile,temp[i]);
		dep1="",dep2="";
		for(int i=0;i<temp[0].length();i++) if(temp[0][i]!=' ') dep1 += temp[0][i];
		for(int i=0;i<temp[1].length();i++) if(temp[1][i]!=' ') dep2 += temp[1][i];
		for(int i=0; i<dep1.length(); i++) dep1[i] = toupper(dep1[i]);
		for(int i=0; i<dep2.length(); i++) dep2[i] = toupper(dep2[i]);
		
		if((dep1+" "+dep2 != nomeTemp+" "+cognomeTemp) and temp[0]!=""){
			for(int i = 0; i < 16; i++) SaveFile << temp[i] << endl;
			if(temp[15]=="1") for(int i = 16; i < 20; i++) SaveFile << temp[i] << endl;
		}
		else if((dep1+" "+dep2 == nomeTemp+" "+cognomeTemp) and cont!=_q ){
			for(int i = 0; i < 16; i++) SaveFile << temp[i] << endl;
			if(temp[15]=="1") for(int i = 16; i < 20; i++) SaveFile << temp[i] << endl;
			cont++;
		}
		else if((dep1+" "+dep2 == nomeTemp+" "+cognomeTemp) and cont==_q){ 
		string risp="", risp2="";
		do{
			for(int i = 0; i < 15; i++){ // stampa menù
			cout << i+1 << ") "<< temp2[i] << temp[i] << endl; 
			}
			if(temp[15] == "1"){
				cout << "16) "<< temp2[15] << "S" << endl;
				for(int j=16; j<20; j++)cout << j+1 << ") "<< temp2[j] << temp[j] << endl;
			}else if(temp[15] == "0") cout << "16) "<< temp2[15] << "N" << endl;
			
			 // menù modifica
				do{
					cout << "Cosa vuoi modificare?(numero): " <<endl ;
					cout << "Scelta ---->>: ";
					getline(cin,risp);
				}while(risp!="1" and risp!="2" and risp!="3" and risp!="4" and risp!="5" and risp!="6" and risp!="7" 
				and risp!="8" and risp!="9" and risp!="10" and risp!="11" and risp!="12" and risp!="13" and risp!="14"
				and risp!="15" and risp!="16" and risp!="17" and risp!="18" and risp!="19" and risp!="20");
				if(risp.length()==1){
					switch(risp[0]){
						case '1':{ //nome
							cout << temp2[0]; getline(cin,temp[0]); Accenti(temp[0]);
							break;
						}
						case '2':{ //cognome
							cout << temp2[1]; getline(cin,temp[1]); Accenti(temp[1]);
							break;
						}
						case '3':{ //natoA
							cout << temp2[2]; getline(cin,temp[2]); Accenti(temp[2]);
							break;
						}
						case '4':{ //Nato il
							cout << temp2[3]; getline(cin,temp[3]); Accenti(temp[3]);
							break;
						}
						case '5':{ //Residente a
							cout << temp2[4]; getline(cin,temp[4]); Accenti(temp[4]);
							break;
						}
						case '6':{ //Residente in via
							cout << temp2[5]; getline(cin,temp[5]); Accenti(temp[5]);
							break;
							}
						case '7':{ //Documento tipo
							cout << temp2[6]; getline(cin,temp[6]); Accenti(temp[6]);
							break;
						}
						case '8':{ //Documento N.
							cout << temp2[7]; getline(cin,temp[7]); Accenti(temp[7]);
							break;
						}
						case '9':{ //Rilasciato da
							cout << temp2[8]; getline(cin,temp[8]); Accenti(temp[8]);
							break;
						}
					}
				}
				else{
					if(risp=="10") { // Rilasciato il
						cout << temp2[9]; getline(cin,temp[9]); Accenti(temp[9]);
					}
					else if(risp=="11"){ // Numero licenza
						cout << temp2[10]; getline(cin,temp[10]); Accenti(temp[10]);
					}
					else if(risp=="12"){ // Categoria
						cout << temp2[11]; getline(cin,temp[11]); Accenti(temp[11]);
					}
					else if(risp=="13"){ //mezzoN
						cout << temp2[12]; getline(cin,temp[12]); Accenti(temp[12]);
					}
					else if(risp=="14"){ //Targa
						cout << temp2[13]; getline(cin,temp[13]); Accenti(temp[13]);
					}
					else if(risp=="15"){ //Modello
						cout << temp2[14]; getline(cin,temp[14]); Accenti(temp[14]);
					}							
					else if(risp=="16"){ //Minore?
						do{
							cout << temp2[15]; getline(cin,temp[15]);
						}while(temp[15] != "s" and temp[15] != "S" and temp[15] != "n" and temp[15] != "N");
						if(temp[15] == "S" or temp[15] == "s"){
							temp[15] = "1";
							cout << temp2[16]; getline(cin,temp[16]); Accenti(temp[16]);
							cout << temp2[17]; getline(cin,temp[17]); Accenti(temp[17]);
							cout << temp2[18]; getline(cin,temp[18]); Accenti(temp[18]);
							cout << temp2[19]; getline(cin,temp[19]); Accenti(temp[19]);
						}
						else if(temp[15] == "N" or temp[15] == "n") temp[15] = "0";
					}					    
					else if(risp=="17"){ //Nome Minore
						cout << temp2[16]; getline(cin,temp[16]); Accenti(temp[16]);
					}
					else if(risp=="18"){ //Cognome Minore
						cout << temp2[17]; getline(cin,temp[17]); Accenti(temp[17]);
					}
					else if(risp=="19"){ //Minore nato a
						cout << temp2[18]; getline(cin,temp[18]); Accenti(temp[18]);
					}
					else if(risp=="20"){ //Minore nato il
						cout << temp2[19]; getline(cin,temp[19]); Accenti(temp[19]);
					}
				}
					do{
						cout << "Modificare altro?(S o N): ";
						getline(cin,risp2);
					}while(risp2!="s" and risp2!="S" and risp2!="n" and risp2!="N");
					if(risp2=="s" or risp2=="S") {
						system("CLS"); cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
					}
			}while(risp2=="s" or risp2=="S");
			for(int i = 0; i < 16; i++) SaveFile << temp[i] << endl;
			if(temp[15] == "1") for(int i = 16; i < 20; i++) SaveFile << temp[i] << endl;
			else if(temp[15] == "0") for(int i = 16; i < 20; i++) temp[i] = "";
		}	
	}
	OpenFile.close(); SaveFile.close();
	remove("DataBaseClienti/DataBase.txt");
	rename("DataBaseClienti/Copia.txt","DataBaseClienti/DataBase.txt");
}

void Elimina(){
	string nomeElim, cognomeElim, nomeTemp="", cognomeTemp="", dep1="", dep2="";
	
	bool w;
	do{
		cout << "Nome del cliente da eliminare: ";
		getline(cin,nomeElim);
		Accenti(nomeElim);
		cout << "Cognome del cliente da eliminare: ";
		getline(cin,cognomeElim);
		Accenti(cognomeElim);
		if(!Search(nomeElim,cognomeElim)) {
			w = false;
			system("CLS"); 
			cout << "Cliente non trovato! " << endl;
			cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
		}else w = true;
	}while(!w);
	for(int i=0;i<nomeElim.length();i++) if(nomeElim[i]!=' ') nomeTemp += nomeElim[i];
	for(int i=0;i<cognomeElim.length();i++) if(cognomeElim[i]!=' ') cognomeTemp += cognomeElim[i];
	for(int i=0; i<nomeTemp.length(); i++) nomeTemp[i] = toupper(nomeTemp[i]);
	for(int i=0; i<cognomeTemp.length(); i++) cognomeTemp[i] = toupper(cognomeTemp[i]);
	int cont = 1;
	ifstream OpenFile("DataBaseClienti/DataBase.txt");
	ofstream SaveFile("DataBaseClienti/Copia.txt");
	while(!OpenFile.eof()){
		dep1="",dep2="";
		string temp[20]; for(int i = 0; i < 20; i++) temp[i] = "";
		for(int i = 0; i < 16; i++) getline(OpenFile,temp[i]);
		if(temp[15] == "1") for(int i = 16; i < 20; i++) getline(OpenFile,temp[i]);
		for(int i=0;i<temp[0].length();i++) if(temp[0][i]!=' ') dep1 += temp[0][i];
		for(int i=0;i<temp[1].length();i++) if(temp[1][i]!=' ') dep2 += temp[1][i];
		for(int i=0; i<dep1.length(); i++) dep1[i] = toupper(dep1[i]);
		for(int i=0; i<dep2.length(); i++) dep2[i] = toupper(dep2[i]);
		
		if((dep1+" "+dep2 != nomeTemp+" "+cognomeTemp) and temp[0]!=""){
			for(int i = 0; i < 16; i++) SaveFile << temp[i] << endl;
			if(temp[15] == "1") for(int i = 16; i < 20; i++) SaveFile << temp[i] << endl;
		}
		else if((dep1+" "+dep2 == nomeTemp+" "+cognomeTemp) and cont!=_q){
			for(int i = 0; i < 16; i++) SaveFile << temp[i] << endl;
			if(temp[15]=="1") for(int i = 16; i < 20; i++) SaveFile << temp[i] << endl;
			cont++;
		}
		else if((dep1+" "+dep2 == nomeTemp+" "+cognomeTemp) and cont==_q) cont++;
	}
	OpenFile.close(); SaveFile.close();
	remove("DataBaseClienti/DataBase.txt");
	rename("DataBaseClienti/Copia.txt","DataBaseClienti/DataBase.txt");
	system("CLS");
	cout << "Cliente eliminato! " << endl;
}

void EliminaTutto(){
	string t;
	cout << endl;
	do{
		cout << "Sicuro di voler svuotare l'intero DataBase?(S o N): ";
		getline(cin,t);
	}while(t!="n" and t!="N" and t!="s" and t!="S");
	if(t=="s" or t =="S"){
		ofstream OpenFile("DataBaseClienti/DataBase.txt");
		OpenFile.close();
		system("CLS");
		cout << "DataBase svuotato! " << endl;
	} else system("CLS");
}

int main(){
	string menu;
	do{ //Menù
		do{
			cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
			cout <<"1) Per Visualizzare il DataBase;" << endl
				<< "2) Per Aggiungere un cliente; " << endl
				<< "3) Per Modificare un cliente; "<< endl
				<< "4) Per Eliminare un cliente; " << endl
				<< "5) Per Svuotare l'intero DataBase; " << endl
				<< "6) Per Iniziare a lavorare; " << endl
				<< "Scegli--->>  "; getline(cin,menu);
			if(menu != "1" and menu != "2" and menu != "3" and menu != "4" and menu != "5" and menu != "6"){
				system("CLS"); cout << "Selezione non valida! " << endl << endl;
			}
		}while(menu != "1" and menu != "2" and menu != "3" and menu != "4" and menu != "5" and menu != "6");
		switch(menu[0]){
			case '1':{ system("CLS"); Visualizza(); break;}
			case '2':{ Aggiungi(); system("CLS"); break;}
			case '3':{ Modifica(); system("CLS"); break;}
			case '4':{ Elimina(); /*system("CLS")*/; break;}
			case '5':{ EliminaTutto(); /*system("CLS");*/ break;}
			case '6':{system("CLS"); break;}
		}
	}while(menu != "6");
	while(true){
		cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
		nome="", cognome="", natoA="", natoIl="", residenteA="", residenteVia="",documentoT="",
		documentoN="", rilasciatoDa="", rilasciatoIl="", nLicenza="", categoria="", KMA="", mi="",
		nM ="", cM="", natoM="", dataM="";
		string nv,pn;
		do{ // Chiede se il cliente è nuovo o vecchio
			cout << "Cliente nuovo o vecchio?: "; 
			getline(cin,nv);
			if(nv!="n" and nv!="N" and nv!="v" and nv!="V") { system("CLS");
			cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
			}
		}while(nv!="n" and nv!="N" and nv!="v" and nv!="V");
		
		do{ // Chiede se il cliente è privato o noleggiante
			cout << "Privato o noleggiante?: ";
			getline(cin,pn);
			if(pn!="p" and pn!="P" and pn!="n" and pn!="N"){ system("CLS");
			cout << "________________________________PISTA DEL SOLE________________________________" << endl << endl;
			cout << "Cliente nuovo o vecchio?: " << nv << endl; 
			}
		}while(pn!="p" and pn!="P" and pn!="n" and pn!="N");
		
		if((nv=="n" or nv=="N") and (pn=="p" or pn=="P")){
			do{ // Chiede se Kart, Moto o Auto
				cout << "Kart, Moto o Auto?: ";
				getline(cin,KMA);
			}while(KMA != "k" and KMA != "K" and KMA != "m" and KMA != "M" and KMA != "a" and KMA != "A");
			
			InfoCliente('p');
			string rispM;
			do{
				cout<<"C'e' un minorenne?: ";
				getline(cin,rispM);
			}while(rispM!="n" and rispM!="N" and rispM!="s" and rispM!="S");
			if(rispM=="s" or rispM == "S"){
				InfoMinorenne();
				mi = "1";
			}
			else mi = "0";
			SaveInfo();
			FacPrivato();
		}
		else if((nv=="n" or nv=="N") and (pn=="n" or pn=="N")){
			
			InfoCliente('n');
			string rispM;
			do{
				cout<<"C'e' un minorenne?: ";
				getline(cin,rispM);
			}while(rispM!="n" and rispM!="N" and rispM!="s" and rispM!="S");
			if(rispM=="s" or rispM == "S") {
				InfoMinorenne();
				mi = "1";
			}
			else mi = "0";
			SaveInfo();
			FacNoleggio();
		}
		else if((nv=="v" or nv=="V") and (pn=="p" or pn=="P")){
			do{ // Chiede se Kart, Moto o Auto
				cout << "Kart, Moto o Auto?: ";
				getline(cin,KMA);
			}while(KMA != "k" and KMA != "K" and KMA != "m" and KMA != "M" and KMA != "a" and KMA != "A");
			string searchNome, searchCognome;
			string rispM="",rispM2="";
			bool w;
			do{
				cout << "Nome: ";
				getline(cin,searchNome);
				cout << "Cognome: ";
				getline(cin,searchCognome);	
				
				if(Search(searchNome,searchCognome)){
					w = true;
					if(mi=="1"){
						cout << " e c'e' un minorenne! " << endl;
						do{
							cout<<"Aggiungere il Minorenne?: ";
							getline(cin,rispM);
						}while(rispM!="n" and rispM!="N" and rispM!="s" and rispM!="S");
					}
					else{ cout << endl;
						do{
							cout<<"Aggiungere un Minorenne?: ";
							getline(cin,rispM2);
						}while(rispM2!="n" and rispM2!="N" and rispM2!="s" and rispM2!="S");
						
					}
				} else w = false;
			}while(!w);
			if(rispM=="n" or rispM=="N") mi = "0";
			if(rispM2=="s" or rispM2 == "S"){
				InfoMinorenne();
				mi = "1";
			} else if(rispM2 =="n" or rispM2 == "N") mi = "0";
			FacPrivato();
		}
		else if((nv=="v" or nv=="V") and (pn=="n" or pn=="N")){
			string searchNome, searchCognome;
				string rispM="", rispM2="";
			bool w;
			do{
				cout << "Nome: ";
				getline(cin,searchNome);
				cout << "Cognome: ";
				getline(cin,searchCognome);
				if(Search(searchNome,searchCognome)){
					w = true;
					if(mi=="1"){
						cout << " e c'e' un minorenne! " << endl;
						do{
							cout<<"Aggiungere il Minorenne?: ";
							getline(cin,rispM);
						}while(rispM!="n" and rispM!="N" and rispM!="s" and rispM!="S");
					}
					else{ cout << endl;
						do{
							cout<<"Aggiungere un Minorenne?: ";
							getline(cin,rispM2);
						}while(rispM2!="n" and rispM2!="N" and rispM2!="s" and rispM2!="S");
					}
				} else w = false;
			}while(!w);
			if(rispM=="n" or rispM=="N") mi = "0";
			if(rispM2=="s" or rispM2 == "S"){
				InfoMinorenne();
				mi = "1";
			}
			FacNoleggio();
		}
		system("PAUSE");
		system("start DataBaseClienti/Stampa.doc");
		system("CLS");
	}
}
