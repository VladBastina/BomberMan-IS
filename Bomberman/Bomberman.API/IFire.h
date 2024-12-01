#include <utility>
#include <string>
class IFire {
public:

	virtual std::pair<int, int> GetPosition() const=0;
	virtual float GetTimer() const = 0;
	virtual std::string GetImagePath() const = 0;
	
	virtual void SetPosition(const std::pair<int, int>& position) = 0;
	virtual void SetTimer(const float& timer) = 0;
	virtual bool HasExpired(const float& elapsedTime) = 0;
};