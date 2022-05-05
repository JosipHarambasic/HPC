## Exercise 8.1
The snapshot jharam_cowsay_gcc_openmp_openmpi is the snapshot which works for
the cowsay, gcc, openmp and openmpi. I tested it by using the solutions repository
and run the mpicc and mpirun which worked.

## Exercise 8.2
- The docker file can be found [here](https://github.com/JosipHarambasic/HPC/blob/main/exsession08/Dockerfile)
- Due to compatibility issues I used ubuntu:bionic instead of trusty.
- To push the docker file into the repo I used:
```docker tag poisson:latest josip97/poisson:latest```,
```docker push josip97/poisson:latest```
- [Dockerhub](https://hub.docker.com/repository/docker/josip97/poisson) repo.
- Run the docker image on the VM works ```docker run josip97/poisson```
- Since an error occurs for the display we need to use the command 