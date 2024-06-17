// Define the LoadBalancer class to manage the web servers and request queue.
// Include properties like a vector of WebServer objects, a RequestQueue object,
// and load balancing algorithm parameters. Implement methods for
// adding/removing servers, distributing requests, and monitoring the load.

// Load Balancer
// - Queue of requests
// - Keeps track of time.

#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "request.h"
#include "webserver.h"
#include <queue>
#include <vector>

class LoadBalancer {
  std::vector<WebServer> servers;
  std::queue<Request> requestQueue;
  int simulationTime;
  int currentTime;

public:
  /**
   * @brief The LoadBalancer class represents a load balancer in a system.
   *
   * This class is responsible for distributing incoming requests across
   * multiple servers to ensure efficient utilization of resources and optimal
   * performance.
   */
  LoadBalancer() {
    simulationTime = 0;
    currentTime = 0;
  }
  /**
   * @brief Constructs a LoadBalancer object with the specified number of
   * servers and simulation time.
   *
   * @param num_servers The number of servers to be created.
   * @param simulation_time The duration of the simulation in time units.
   */
  LoadBalancer(int num_servers, int simulation_time) {
    for (int i = 0; i < num_servers; i++) {
      WebServer server = WebServer(i);
      servers.push_back(server);
    }
    simulationTime = simulation_time;
    currentTime = 0;
  }
  /**
   * Adds a request to the request queue.
   *
   * @param request The request to be added.
   */
  void addRequest(Request request) { requestQueue.push(request); }
  /**
   * Displays the current status of the load balancer.
   * This includes the current time, simulation time, request queue size,
   * and the status of each server in the load balancer.
   */
  void displayStatus() {
    std::cout << "Current Time: " << currentTime << std::endl;
    std::cout << "Simulation Time: " << simulationTime << std::endl;
    std::cout << "Request Queue Size: " << requestQueue.size() << std::endl;
    for (int i = 0; i < servers.size(); i++) {
      std::cout << "Server " << i << " Status: ";
      if (servers[i].isActive()) {
        std::cout << "Active" << std::endl;
      } else {
        std::cout << "Inactive" << std::endl;
      }
    }
  }
  /**
   * Returns the current time.
   *
   * @return The current time.
   */
  int getCurrentTime() { return currentTime; }
  /**
   * Returns the simulation time.
   *
   * @return The simulation time.
   */
  int getSimulationTime() { return simulationTime; }
  /**
   * Adds a web server to the load balancer.
   *
   * @param server The web server to be added.
   */
  void addServer(WebServer server) { servers.push_back(server); }
  /**
   * Removes a web server from the load balancer.
   *
   * @param server The web server to be removed.
   */
  void removeServer(WebServer server) { servers.pop_back(); }
  /**
   * Adds a request to the request queue.
   * @param request The request to be added to the queue.
   */
  void queueRequest(Request request) { requestQueue.push(request); }
  /**
   * Returns the size of the request queue.
   *
   * @return The size of the request queue.
   */
  int getRequestQueueSize() { return requestQueue.size(); }
  /**
   * Distributes requests from the request queue to the active servers.
   * This function iterates through the servers and checks if they are active.
   * If a server is active and there is a request in the request queue, it
   * processes the request. The processed request is removed from the request
   * queue.
   */
  void distributeRequest() {
    for (int i = 0; i < servers.size(); i++) {
      if (!requestQueue.empty()) {
        if (!servers[i].isActive()) {
          servers[i].processRequest(requestQueue.front());
          requestQueue.pop();
        }
      }
    }
  }
  /**
   * Updates the status of the servers based on their request time.
   * If a server is active and its request time is 0, its status is updated to
   * inactive.
   */
  void updateServerStatus() {
    for (int i = 0; i < servers.size(); i++) {
      if (servers[i].isActive()) {
        if (servers[i].getRequestTime() == 0) {
          servers[i].updateStatus(false);
        }
      }
    }
  }
  /**
   * @brief Increments the current time by 1.
   */
  void incrementCurrentTime() { currentTime++; }
};

#endif