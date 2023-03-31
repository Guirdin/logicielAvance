package com.example.eventconsumer;

import java.util.function.Consumer;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Service;

@Service
public class TrackedEventService {

	@Bean
	public Consumer<TrackedEvent> trackedEventConsumer() {
		return (input) -> {
			System.out.println("********************");
			System.out.println(input.toString());
			System.out.println("********************");
		};

	}
}
