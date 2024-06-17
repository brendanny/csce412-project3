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
  LoadBalancer();
  LoadBalancer(int num_servers, int simulation_time);
  ~LoadBalancer();
  void addRequest(Request request);
  void displayStatus();
  int getCurrentTime();
  int getSimulationTime();
  void addServer(WebServer server);
  void removeServer(WebServer server);
  void queueRequest(Request request);
  int getRequestQueueSize();
  void distributeRequest();
  void updateServerStatus();
  void incrementCurrentTime();
};

#endif