// Define the WebServer class to represent a web server.
// Include properties like server ID, status (active/inactive), and request
// processing time. Implement methods for processing requests and updating
// server status.

// Webserver(s)
//  - Takes requests from the Load Balancer
//  - Process the requests
//  - Asks for another

#ifndef WEBSERVER_H
#define WEBSERVER_H
#include "request.h"

class WebServer {
  int serverID;
  bool active;
  int requestTime;

public:
  /**
   * @brief Constructs a new WebServer object.
   *
   * This constructor initializes the WebServer object with default values.
   * The serverID is set to 0, active is set to false, and requestTime is set to
   * 0.
   */
  WebServer() {
    serverID = 0;
    active = false;
    requestTime = 0;
  }

  /**
   * @brief Constructs a WebServer object with the given ID.
   *
   * @param id The ID of the server.
   */
  WebServer(int id) {
    serverID = id;
    active = false;
    requestTime = 0;
  }

  /**
   * Processes the given request and updates the server status.
   *
   * @param request The request to be processed.
   */
  void processRequest(Request request) {
    // Process the request and update the server status.
    requestTime = request.getTime();
    active = true;
  }

  /**
   * @brief Updates the status of the server.
   *
   * This function updates the status of the server to either active or
   * inactive.
   *
   * @param status The new status of the server. Set to true for active, false
   * for inactive.
   */
  void updateStatus(bool status) {
    // Update the server status (active/inactive).
    active = status;
  }

  /**
   * @brief Decrements the request processing time.
   *
   * This function decrements the request processing time by one unit.
   */
  void decrementRequestTime() {
    // Decrement the request processing time.
    if (requestTime > 0) {
      requestTime--;
    }
  }

  /**
   * @brief Returns the request processing time.
   *
   * @return int The request processing time.
   */
  int getRequestTime() {
    // Get the request processing time.
    return requestTime;
  }

  /**
   * @brief Returns the status of the server.
   *
   * @return bool The status of the server.
   */
  bool isActive() {
    // Get the status of the server (active/inactive).
    return active;
  }
};

#endif