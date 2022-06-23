int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_lastID(LinkedList* pArrayListPassenger);
// INFORMES
int controller_countPassengerByClass(LinkedList* pArrayListPassenger, int* cantidadPasajerosFirstClass, int* cantidadPasajerosExecutive, int* cantidadPasajerosEconomyClass);
int controller_filtrerPassengerByClass(LinkedList* pArrayListPassenger);
