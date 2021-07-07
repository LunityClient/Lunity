#include "WebPanel.h"
#include "../../../Utils/Utils.h"

auto WebPanel::getInstance() -> WebPanel* {
	if(instance == nullptr) {
		instance = new WebPanel();
	}
	return instance;
}

auto WebPanel::getSvr() -> httplib::Server* {
	if(this->svr == nullptr) {
		this->svr = new httplib::Server();
	}
	return this->svr;
}

auto WebPanel::makeRequest(string url) -> string {
	try
	{
		// you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
		http::Request request{url};

		// send a get request
		const auto response = request.send("GET");
		string result = std::string{response.body.begin(), response.body.end()};
		return result;
	}
	catch (const std::exception& e)
	{
		Utils::DebugF("Request failed, error: ");
		Utils::DebugF(e.what());
	}
	return "";
}

void WebPanel::start(short port) {
	try {
		this->getSvr()->Get("/panel", [](const httplib::Request& req, httplib::Response& res) {
			res.set_content("Hello World!", "text/plain");
		});

		this->getSvr()->listen("localhost", port);
	}
	catch (const std::exception& e)
	{
		Utils::DebugF("Server start failed: ");
		Utils::DebugF(e.what());
	}

	Utils::DebugF(this->makeRequest("http://wtfismyip.com/test"));
}

void WebPanel::stop() {
	this->getSvr()->stop();
	delete this->svr;
}