package com.tld.producerpoller;

import java.util.Base64;
import java.util.Date;
import java.util.Random;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Supplier;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Service;

@Service
public class TrackedEventService {
//	@Bean
//	public Consumer<TrackedEvent> trackedEventConsumer() {
//		return (input) -> {
//			System.out.println("********************");
//			System.out.println(input.toString());
//			System.out.println("********************");
//		};
//
//	}
	
	@Bean
	public Function <TrackedEvent , TrackedEvent> trackedEventFunction(){
	return (in) -> {	
	Long id=in.getId();
	in.setId(99L);
	//in.setInfoToTrack("message modifie par Function "+id);
	return in;
	};
	}

	@Bean
	public Supplier<TrackedEvent> trackedEventSupplier() {

		return () -> new TrackedEvent(null, giveMeAString(), new Date());
	}

	public String giveMeAString() {
		byte[] array = new byte[7]; // length is bounded by 7
		new Random().nextBytes(array);
		String generatedString = Base64.getEncoder().encodeToString(array);
		return generatedString;
	}
}
