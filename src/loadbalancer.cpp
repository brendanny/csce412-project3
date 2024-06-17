#include "loadbalancer.h"
#include "webserver.h"

/**
 * @brief Constructs a LoadBalancer object.
 * 
 * This constructor initializes the LoadBalancer object with default values for simulationTime and currentTime.
 * 
 */
LoadBalancer::LoadBalancer() {
  // Default constructor.
  simulationTime = 0;
  currentTime = 0;
}
/**
 * @brief Constructs a LoadBalancer object with the specified number of servers and simulation time.
 * 
 * @param num_servers The number of servers to be initialized in the load balancer.
 * @param simulation_time The simulation time for the load balancer.
 */
LoadBalancer::LoadBalancer(int num_servers, int simulation_time) {
  // Initialize the load balancer with the specified number of servers and
  // simulation time.
  for (int i = 0; i < num_servers; i++) {
    WebServer server = WebServer(i);
    servers.push_back(server);
  }
  simulationTime = simulation_time;
  currentTime = 0;
}

/**
 * Generates an initial set of requests and adds them to the request queue.
 * The number of requests generated is twice the maximum number of servers.
 * Each request is assigned a unique ID and a random priority value.
 */
void LoadBalancer::generateInitialRequests() {
  // Generate an initial full queue of requests.
  for (int i = 0; i < maxServers * 2; i++) {
    Request request(i, rand() % 100);
    requestQueue.addRequest(request);
  }
}

/**
 * Adds a new request to the queue at random times.
 */
void LoadBalancer::addRequest() {
  // Add a new request to the queue at random times.
  if (rand() % 100 < 30) {
    Request request(requestQueue.getSize(), rand() % 100);
    requestQueue.addRequest(request);
  }
}

/**
 * Monitors the load of the load balancer and dynamically allocates/deallocates servers based on the load.
 * The monitoring process continues until the current time exceeds the maximum time.
 */
void LoadBalancer::monitorLoad() {
  // Dynamically allocate/deallocate servers based on the load.
  while (getTime() < maxTime) {
    if (requestQueue.getSize() > maxServers) {
      WebServer server;
      addServer(server);
    } else if (requestQueue.getSize() < minServers) {
      removeServer(servers.back());
    }
  }
}

/**
 * Displays the current status of the load balancer.
 * This includes the current time, the number of servers, and the number of requests in the queue.
 */
void LoadBalancer::displayStatus() {
  // Display the load balancer status at regular intervals.
  std::cout << "Load Balancer Status:" << std::endl;
  std::cout << "Time: " << getTime() << std::endl;
  std::cout << "Number of Servers: " << servers.size() << std::endl;
  std::cout << "Number of Requests: " << requestQueue.getSize() << std::endl;
}

/**
 * Get the current time of the load balancer.
 *
 * @return The current time of the load balancer.
 */
int LoadBalancer::getTime() {
  // Get the current time of the load balancer.
  return time;
}

/**
 * @brief Adds a new server to the load balancer.
 * 
 * This function adds a new server to the load balancer's list of servers.
 * 
 * @param server The server to be added.
 */
void LoadBalancer::addServer(WebServer server) {
  // Add a new server to the load balancer.
  servers.push_back(server);
}

/**
 * @brief Removes a server from the load balancer.
 * 
 * This function removes the specified server from the load balancer's list of servers.
 * 
 * @param server The server to be removed.
 */
void LoadBalancer::removeServer(WebServer server) {
  // Remove a server from the load balancer.
  servers.pop_back();
}

/**
 * Distributes a request to a server based on the load balancing algorithm.
 *
 * @param request The request to be distributed.
 */
void LoadBalancer::distributeRequest(Request request) {
  // Distribute a request to a server based on the load balancing algorithm.
  int serverIndex = rand() % servers.size();
  servers[serverIndex].processRequest(request);
}

/**
 * Updates the server status based on request processing time.
 * Decrements the request time for each server and updates the status to false if the request time reaches 0.
 */
void LoadBalancer::updateServerStatus() {
  // Update the server status based on request processing time.
  for (WebServer server : servers) {
    server.decrementRequestTime();
    if (server.getRequestTime() == 0) {
      server.updateStatus(false);
    }
  }
}

/**
 * @brief Updates the current time of the load balancer.
 * 
 * This function increments the current time of the load balancer by one.
 */
void LoadBalancer::incrementCurrentTime() {
  // Update the current time of the load balancer.
  currentTime++;
}