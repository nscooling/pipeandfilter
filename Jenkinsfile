pipeline {
  agent {
    docker {
      image 'gcc7'
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
        isUnix()
        sh 'pwd'
      }
    }
  }
}