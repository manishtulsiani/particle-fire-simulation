# particle-fire-simulation
Particle fire simulation project using SDL.

This is a C++ tutorial simulation project to understand and practice various concepts of C++.

The program has the following classes:
  1. Screen - A screen defines a window of 800X600 pixels. The Screen class supports the following functions:
      a. init - initializes a screen object and required SDL components for rendering, texture and pixel buffer.
      b. setPixel - sets a pixel value in the buffer. The pixel is of the format: RGBA
      c. updateScreen - updates the screen by clearing and rerendering the texture.
      d. boxBlur - blurs the screen pixels.
      e. processEvents - processes all SDL Events till quit.
      f. close - closes and releases all acquired resources.
    
  2. Particle - A particle represents a pixel on the screen. It has an x, y co-ordinate, a constant speed and a moving direction. The update        particle recalculates the new position of the particle.
  
  3. Swarm - A Swarm is a colletion of particles.
  
  The main flow is controlled by ParticleFireExplosion.cpp. The flow control is as follows:
  
      1. Create a screen and a swarm.
      2. Update all the particles of the swarm.
      3. Map each particle to a pixel.
      4. Blur the screen using the previous values of the pixel.
      5. Update the screen.
      6. Check for any events. If closed event is triggered, quit the program, else continue to step 2.
      7. Close the screen and exit.
