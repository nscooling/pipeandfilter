pipeline {
  agent {
    docker {
      image 'docker pull rikorose/gcc-cmake'
    }
    
  }
  stages {
    stage('build') {
      steps {
        echo 'simple pipeline'
      }
    }
    stage('step2') {
      steps {
        sh 'build.sh'
      }
    }
  }
}