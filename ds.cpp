#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

int main() {
	int H, M, S, waitTimeSeconds;

	std::cout << "H: ";
	std::cin >> H;
	std::cout << "M: ";
	std::cin >> M;
	std::cout << "S: ";
	std::cin >> S;

	waitTimeSeconds = (H * 3600) + (M * 60) + S;

	while (waitTimeSeconds > 0) {
		std::cout << "Wait Time: " << waitTimeSeconds << std::flush;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "\r" << std::string(40, ' ') << "\r";
		waitTimeSeconds--;
	}
	
	std::cout << "Shutting Down..." << std::endl;

	InitiateSystemShutdownExW(NULL, NULL, 0, TRUE, FALSE, SHTDN_REASON_FLAG_PLANNED | SHTDN_REASON_MINOR_OTHER);

	return 0;
}
