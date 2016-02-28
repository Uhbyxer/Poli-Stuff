package com.acme.agent;

import jade.core.Runtime;
import jade.core.Profile;
import jade.core.ProfileImpl;
import jade.wrapper.AgentController;
import jade.wrapper.ContainerController;
import jade.wrapper.StaleProxyException;

public class Main {
	public static void main(String[] args) {
		Runtime runtime = Runtime.instance();
		Profile profile = new ProfileImpl();
		profile.setParameter(Profile.MAIN_HOST, "localhost");
		profile.setParameter(Profile.GUI, "true");
		
		ContainerController containerController = runtime.createMainContainer(profile);
		
		try {
			AgentController agentController = containerController.createNewAgent("Hello Agent 1", "com.acme.agent.HelloAgent", null);
			agentController.start();
		} catch (StaleProxyException e) {
			
			e.printStackTrace();
		}
	}
}
