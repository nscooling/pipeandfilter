pipeline {
  agent {
    docker {
      image 'rikorose/gcc-cmake'
    }
    
  }
  stages {
    stage('build') {
      steps {
        sh '''mkdir build
cd build
cmake ..'''
      }
    }
  }
}