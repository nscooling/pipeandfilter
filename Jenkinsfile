pipeline {
  agent {
    docker {
      image 'gcc7'
    }
    
  }
  stages {
    stage('step2') {
      steps {
        isUnix()
        sh 'pwd'
      }
    }
  }
}