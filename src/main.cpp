/**
 * @file main.cpp
 * @brief Entry point for a load balancing simulation program.
 *
 * This program simulates a load balancing system where servers are dynamically
 * allocated and deallocated based on the load. It prompts the user for the
 * number of servers and the duration of the simulation, initializes the load
 * balancer, generates an initial queue of requests, and enters a simulation
 * loop that dynamically manages servers and displays the load balancer status
 * at regular intervals.
 */

#include "loadbalancer.h"
#include "request.h"
#include <fstream>
#include <iostream>

/**
 * @brief Main function: Entry point of the program.
 *
 * Prompts the user for the number of servers and the simulation time,
 * initializes the load balancer with the specified parameters, generates
 * initial requests, and starts the simulation loop. During the simulation,
 * servers are dynamically allocated and deallocated based on the load, and the
 * load balancer status is displayed at regular intervals.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  // Get user input for the number of servers and simulation time.
  int num_servers;
  int simulation_time;
  std::cout << "Enter the number of servers: ";
  std::cin >> num_servers;
  std::cout << "Enter the simulation time: ";
  std::cin >> simulation_time;

  // Create an instance of the LoadBalancer class.
  LoadBalancer load_balancer(num_servers, simulation_time);

  // Generate an initial full queue of requests.
  for (int i = 0; i < num_servers * 100; i++) {
    Request request(i, rand() % 100);
    load_balancer.queueRequest(request);
  }

  //   write queue size to log file
  std::ofstream logFile;
  logFile.open("log.txt");
  logFile << "Queue size: " << load_balancer.getRequestQueueSize() << std::endl;

  for (int i = 0; i < load_balancer.getSimulationTime(); i++) {
    // Add a new request to the queue at random times.
    if (rand() % 100 < 1) {
      Request request(load_balancer.getRequestQueueSize(), rand() % 100);
      //   log request to file
      logFile << "Request ID: " << request.getRequestID() << std::endl;
      //   log request time to file
      logFile << "Request Time: " << request.getTime() << std::endl;
      load_balancer.queueRequest(request);
    }

    // Distribute requests to servers.
    load_balancer.distributeRequest();

    // Update the server status based on request processing time.
    load_balancer.updateServerStatus();

    // Display the load balancer status at regular intervals.
    if (i % 10 == 0) {
      load_balancer.displayStatus();
    }

    // update the current time
    load_balancer.incrementCurrentTime();
  }

  //   write queue size to log file
  logFile << "Queue size: " << load_balancer.getRequestQueueSize() << std::endl;

  return 0;
}