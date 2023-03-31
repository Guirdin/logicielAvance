package com.tld.producerpoller;

import java.util.Date;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ToString
public class TrackedEvent {

	private Long id;
	private String infoToTrack;
	private Date sysDate;
}
