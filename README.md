Methoden der Spieleentwicklung II (100%)
Die ersten Treffen mit Investoren für Ihr Computerspiel sind gut verlaufen. Jetzt geht es darum, Ihren Prototypen auf die richtigen Beine zu stellen und rein objektorientierte Programmierung.
Sie haben inzwischen auch Wissen um die Konzepte der objektorientieren Programmierung erworben, und nun soll in einem ersten Schritt die Konzepte der Abstraktion und Kapselung umgesetzt werden. Hierfür sollen die structs vom letzten Übungszettel in echte C++-Klassen umgesetzt werden. Beachten Sie dabei folgende Aspekte:
	• Die Klassenbezeichnungen enthalten kein _t mehr. Die struct Hero_t wird beispielsweise zu class Hero.
	• Die Funktionen des letzten Exercise Sheets sind als Objektfunktionen umzusetzen.
	• Ersetzen Sie bei den Objekteigenschaften und -funktionen alle unsicheren Konstrukte durch sichere (z.B. char* durch std::string).
	• Verwenden Sie bevorzugt Call-by-Reference für komplexe Objekte mit Refenzen statt Pointern (und vergessen Sie das const Keyword nicht, wenn ein Objekt nicht verändert werden soll).
	• Achten Sie auf eine saubere Trennung zwischen Deklaration/Definition Ihrer Klassen (Header-Datei) und der Implementierungen der Objektfunktionen (cpp-Datei).
	• Jede Klasse ist in eigenen Quelldateien zu speichern (hero.{h, cpp}, character.{h, cpp} und item.{h, cpp}). Die main-Funktion sollte in der Datei main.cpp zu finden sein.
	• Weisen Sie allen Objektfunktionen und -variablen passende Sichtbarkeiten zu.
	• Implementieren Sie für die Objektvariablen entsprechende Getter und Setter dort, wo es Sinn macht.
	• Für Arrays sollen die Getter (und falls erforderlich auch die Setter) als Argument den entsprechenden Slot übergeben bekommen. D.h. die Setter und Getter arbeiten nicht auf dem ganzen Array, sondern auf den einzelnen Elementen (z.B. Item* getInventory(int index)).


Fügen Sie zusätzlich noch folgende Funktionalität hinzu:
	• int addInventarItem(const Item& item) (Klassen Hero und Character): Der übergebene Gegenstand wird zum Inventar der Heldin bzw. des Charakters hinzugefügt. Der Rückgabewert entspricht dem Slotplatz (= Stelle im Array), an dem der Gegenstand eingereiht wurde. Sind alle Plätze belegt, soll der Wert -1 zurückgegeben werden.

	• int addEquipmentItem(const item& item) (Klasse Hero): Der übergebene Gegenstand wird zur Ausrüstung der Heldin inzugefügt. Der Rückgabewert entspricht dem Slotplatz (= Stelle im Array), an dem der Gegenstand eingereiht wurde. Sind alle Plätze belegt, soll der Wert -1 zurückgegeben werden.

	• Item removeInventarItem(int slot) (Klassen Hero und Character): Es wird der Gegenstand an der entsprechenden Stelle im Inventar der Heldin bzw. des Charakters entfernt und zurückgegeben. Falls der angegeben Slot keinen gültigen Gegenstand enthält oder ein ungültiger Slot angegeben wurde, soll die Objektvariable isValid des zurückgegebenen Objekts auf false gesetzt werden.

	• Item removeEquipmentItem(int slot) (Klasse Hero): Es wird der Gegenstand an der entsprechenden Stelle aus der Ausruestung der Heldin entfernt und zurückgegeben. Falls der angegeben Slot keinen gültigen Gegenstand enthält oder ein ungültiger Slot angegeben wurde, soll die Objektvariable isValid des zurückgegebenen Objekts auf false gesetzt werden.

	• Ist die Heldin im Kampf gegen einen Charakter erfolgreich, wird ein zufälliger Gegenstand aus dem Inventar des Charakters ins Inventar der Heldin übertragen. Ist kein Platz verfügbar, soll die Meldung Kein Platz mehr vorhanden! auf std::cout ausgegeben werden.

	• Achten Sie darauf, dass Sie in allen Ihren Objektfunktionen die Eingabeparameter auf Gültigkeit überprüfen (z.B.: ob slot einen gültigen Array-Index enthält) und dafür sorgen, dass ein Objekt immer in einem gültigen Zustand bleibt und keine Buffer-Overflows bzw. -Underflows auftreten können.

Implementieren Sie wieder in der main()-Funktion ein Beispielprogramm, das die Heldin gegen 2 Feinde kämpfen lässt. Nachdem die Helding beide Feinde besiegt hat, sollen alle im Kampf gewonnenen Ausrüstungsgegenstände verkauft werden.




![Uploading image.png…]()
