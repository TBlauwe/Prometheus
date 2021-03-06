#include "../include/persona.h"

#define FMT_HEADER_ONLY // define once before loading spdlog, otherwise fmt is not loaded as header only which causes linking error
#ifndef _DEBUG
#define DOCTEST_CONFIG_DISABLE
#endif

#include <iostream>
#include <spdlog/spdlog.h>
#include <doctest/doctest.h>

namespace Engine{

	void initialize(){
		spdlog::set_level(spdlog::level::trace);
		spdlog::set_pattern("%^[%8l]%$ %v");
		spdlog::info("Initialization complete !");
	}

	void run(){
		//spdlog::info("shouting ...");
	}

	void shutdown(){
		spdlog::info("Shutdown complete !");
	}
}

int fact(int n) {
    return n <= 1 ? 1 : fact(n - 1) * n;
}

TEST_CASE("testing the factorial function") {
    CHECK(fact(0) == 1);
    CHECK(fact(1) == 1);
    CHECK(fact(2) == 2);
    CHECK(fact(3) == 6);
    CHECK(fact(10) == 3628800);
}
