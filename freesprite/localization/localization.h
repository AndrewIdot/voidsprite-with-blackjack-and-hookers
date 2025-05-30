#pragma once

#define TL(a) g_getLocString(a)

struct LocalizationData {
	std::string langName;
	std::string langCredit;
	std::map<std::string, std::string> kvs;
};

//extern std::map<std::string, LocalizationData> g_localizations;	//key: locale name (en-us)

std::map<std::string, LocalizationData>& getLocalizations();
std::string g_getLocString(std::string key);
double g_getLocCompletionPercentage(std::string locale);